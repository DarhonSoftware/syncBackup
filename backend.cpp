#include "backend.h"
#include <QtCore>
#include <QtQuick>
#include "global.h"

CBackend::CBackend(QQmlApplicationEngine *pEngine)
    : QObject(pEngine)
{
    //Capture Engine for future use
    m_pEngine = pEngine;

    //Initiate parameters
    setIsRunning(false);

    //Load HTML assets
    QFile File;
    File.setFileName(":/html/excinchelp.html");
    File.open(QIODevice::ReadOnly);
    setExcIncHelp(File.readAll());
    File.close();

    File.setFileName(":/html/help.html");
    File.open(QIODevice::ReadOnly);
    setHelp(File.readAll());
    File.close();

    //Add model into QML context
    QQmlContext *pRootContext = m_pEngine->rootContext();
    m_ModelExc.setProxyModel(1);
    pRootContext->setContextProperty("modelExc", &m_ModelExc);
    m_ModelInc.setProxyModel(1);
    pRootContext->setContextProperty("modelInc", &m_ModelInc);

    //Initialize Process
    m_Process.setProcessChannelMode(QProcess::SeparateChannels);
    m_Process.setReadChannel(QProcess::StandardOutput);

    //Set environment viriable
    QProcessEnvironment Environment = QProcessEnvironment::systemEnvironment();
    Environment.insert("SSH_ASKPASS", "/app/bin/ksshaskpass");
    Environment.insert("SSH_ASKPASS_REQUIRE", "prefer");
    m_Process.setProcessEnvironment(Environment);

    //Connect process to slots
    connect(&m_Process, &QProcess::errorOccurred, this, &CBackend::errorProcess);
    connect(&m_Process, &QProcess::started, this, &CBackend::startedProcess);
    connect(&m_Process, &QProcess::finished, this, &CBackend::finishedProcess);
    connect(&m_Process, &QProcess::readyReadStandardOutput, this, &CBackend::readProcess);
}

CBackend::~CBackend()
{
    m_Process.close();
}

void CBackend::init()
{
    //Load configuration from file
    QSettings Settings;
    Settings.beginGroup("Settings");
    QString sFileName = Settings.value("conf_file", "").toString();
    Settings.endGroup();
    resetConfiguration();
    if (!sFileName.isEmpty())
        if (!loadConfiguration(sFileName))
            sFileName.clear();

    //Set configuration file name
    setConfFileName(sFileName);
}

void CBackend::end()
{
    //Save configuration to file
    QString sFileName = confFileName();
    if (!sFileName.isEmpty())
        if (!saveConfiguration(sFileName))
            sFileName.clear();

    //Save configuration file name
    QSettings Settings;
    Settings.beginGroup("Settings");
    Settings.setValue("conf_file", sFileName);
    Settings.endGroup();
}

void CBackend::parseArguments(QStringList *plsArguments)
{
    //Insert general arguments
    plsArguments->append("--times");

    //Insert arguments as per configuration file
    if (group())
        plsArguments->append("--group");
    if (owner())
        plsArguments->append("--owner");
    if (perms())
        plsArguments->append("--perms");
    if (links())
        plsArguments->append("--links");
    if (update())
        plsArguments->append("--update");
    if (del())
        plsArguments->append("--delete");
    if (deleteExcluded())
        plsArguments->append("--delete-excluded");
    if (ignoreNonExisting())
        plsArguments->append("--ignore-non-existing");
    if (ignoreExisting())
        plsArguments->append("--ignore-existing");
    if (recursive())
        plsArguments->append("--recursive");
    if (maxSize())
        plsArguments->append(QString("--max-size=%1%2").arg(maxSizeValue()).arg(m_lsUnits.at(unit())));

    if (fromPort() != "-1")
        plsArguments->append(QString("--rsh=ssh -p %1").arg(fromPort()));
    if (toPort() != "-1")
        plsArguments->append(QString("--rsh=ssh -p %1").arg(toPort()));

    for (int i = 0; i < m_ModelInc.rowCount(); i++)
        plsArguments->append("--filter=+_" + m_ModelInc.item(i)->text());

    for (int i = 0; i < m_ModelExc.rowCount(); i++)
        plsArguments->append("--filter=-_" + m_ModelExc.item(i)->text());

    //Insert arguments for Origin and Destination
    plsArguments->append(from() + "/");
    plsArguments->append(to());
}

bool CBackend::run(bool bDryRun)
{
    QStringList lsArguments;

    //Validate
    QDir Dir;
    if ((from().isEmpty()) || (to().isEmpty()) || ((!Dir.exists(from())) && (!Dir.exists(to())))) {
        setErrorMessage(tr("You have one of the following problems with the source/destination:") + "\n - "
                        + tr("The source or destination path is empty.") + "\n - " + tr("One of the directories does not exist.") + "\n - "
                        + tr("Source and destination are ssh remote."));
        return false;
    }

    //Insert general arguments
    lsArguments.append("--verbose");
    lsArguments.append("--human-readable");

    //Insert arguments as per main window options
    if (bDryRun)
        lsArguments.append("--dry-run");

    //Append all remaining parameters
    parseArguments(&lsArguments);

    //Call external process
    m_Process.start("rsync", lsArguments);
    return true;
}

void CBackend::cancel()
{
    m_Process.terminate();
}

QString CBackend::exportCommandLine()
{
    QStringList lsArguments;
    parseArguments(&lsArguments);
    return QString("rsync " + lsArguments.join(" "));
}

void CBackend::copyToClipboard(const QString &s)
{
    QGuiApplication::clipboard()->setText(s);
}

QString CBackend::displayConfFileName(const QString &s)
{
    if (s.isEmpty())
        return tr("-no-config-file-");
    return QString("-" + QFileInfo(s).baseName() + "-");
}

QString CBackend::translatePathfromQML(const QString &s, bool bFile)
{
    QString sFile = QString(s).remove("file://");
    if (bFile)
        return sFile;
    return QFileInfo(sFile).path();
}

QStringList CBackend::modelToStringList(QStandardItemModel *pModel)
{
    QStringList StringList;
    for (int i = 0; i < pModel->rowCount(); i++)
        StringList.append(pModel->item(i)->text());
    return StringList;
}

void CBackend::stringListToModel(const QStringList &StringList, QStandardItemModel *pModel)
{
    pModel->clear();
    for (int i = 0; i < StringList.count(); i++)
        pModel->appendRow(new QStandardItem(StringList.at(i)));
}

bool CBackend::saveConfiguration(const QString &sFile)
{
    QFile File;

    File.setFileName(sFile);
    if (!File.open(QIODevice::WriteOnly))
        return false;
    QDataStream Stream(&File);
    Stream.setVersion(QDataStream::Qt_6_0);

    Stream << (quint32) MAGIC_FILE_MARK;
    Stream << group();
    Stream << owner();
    Stream << perms();
    Stream << links();
    Stream << update();
    Stream << del();
    Stream << deleteExcluded();
    Stream << ignoreNonExisting();
    Stream << ignoreExisting();
    Stream << recursive();
    Stream << maxSize();
    Stream << maxSizeValue();
    Stream << unit();
    Stream << modelToStringList(&m_ModelExc);
    Stream << modelToStringList(&m_ModelInc);
    Stream << from();
    Stream << to();
    Stream << fromPort();
    Stream << toPort();

    File.close();
    return true;
}

bool CBackend::loadConfiguration(const QString &sFile)
{
    QFile File;

    File.setFileName(sFile);
    if (!File.open(QIODevice::ReadOnly))
        return false;
    QDataStream Stream(&File);
    Stream.setVersion(QDataStream::Qt_6_0);

    bool bAux;
    quint32 uiAux;
    QString sAux;
    QStringList lsAux;

    Stream >> uiAux;
    if (uiAux != MAGIC_FILE_MARK) {
        File.close();
        return false;
    }

    Stream >> bAux;
    setGroup(bAux);
    Stream >> bAux;
    setOwner(bAux);
    Stream >> bAux;
    setPerms(bAux);
    Stream >> bAux;
    setLinks(bAux);
    Stream >> bAux;
    setUpdate(bAux);
    Stream >> bAux;
    setDel(bAux);
    Stream >> bAux;
    setDeleteExcluded(bAux);
    Stream >> bAux;
    setIgnoreNonExisting(bAux);
    Stream >> bAux;
    setIgnoreExisting(bAux);
    Stream >> bAux;
    setRecursive(bAux);
    Stream >> bAux;
    setMaxSize(bAux);
    Stream >> uiAux;
    setMaxSizeValue(uiAux);
    Stream >> uiAux;
    setUnit(uiAux);
    Stream >> lsAux;
    stringListToModel(lsAux, &m_ModelExc);
    Stream >> lsAux;
    stringListToModel(lsAux, &m_ModelInc);
    Stream >> sAux;
    setFrom(sAux);
    Stream >> sAux;
    setTo(sAux);
    Stream >> sAux;
    setFromPort(sAux);
    Stream >> sAux;
    setToPort(sAux);

    File.close();
    return true;
}

void CBackend::resetConfiguration()
{
    setGroup(true);
    setOwner(true);
    setPerms(true);
    setLinks(true);
    setUpdate(true);
    setDel(false);
    setDeleteExcluded(false);
    setIgnoreNonExisting(false);
    setIgnoreExisting(false);
    setRecursive(true);
    setMaxSize(false);
    setMaxSizeValue(0);
    setUnit(0);
    m_ModelExc.clear();
    m_ModelInc.clear();
    setFrom(QString());
    setTo(QString());
    setFromPort("-1");
    setToPort("-1");
}

void CBackend::addInclude(const QString &sPath)
{
    m_ModelInc.appendRow(new QStandardItem(sPath));
}

void CBackend::addExclude(const QString &sPath)
{
    m_ModelExc.appendRow(new QStandardItem(sPath));
}

void CBackend::removeInclude(int iRow)
{
    if (iRow == -1)
        return;
    m_ModelInc.removeRow(iRow);
}

void CBackend::removeExclude(int iRow)
{
    if (iRow == -1)
        return;
    m_ModelExc.removeRow(iRow);
}

void CBackend::errorProcess(QProcess::ProcessError iError)
{
    emit processOutput(QString("\n" + tr("ERROR [%1] REPORTED BY THE BACKEND DURING EXCECUTION")).arg(iError));
    emit processOutput(m_Process.readAllStandardError());
    setIsRunning(false);
}

void CBackend::startedProcess()
{
    setIsRunning(true);
}

void CBackend::finishedProcess(int iExitCode, QProcess::ExitStatus iExitStatus)
{
    if (iExitStatus == QProcess::CrashExit) {
        emit processOutput(QString("\n" + tr("BACKEND HAS CRASHED")));
    }

    if (iExitCode != 0) {
        emit processOutput(QString("\n" + tr("ERROR [%1] REPORTED BY THE BACKEND AT EXIT")).arg(iExitCode));
        emit processOutput(m_Process.readAllStandardError());
    }
    setIsRunning(false);
}

void CBackend::readProcess()
{
    while (m_Process.canReadLine()) {
        QByteArray BA = m_Process.readLine();
        if ((!BA.trimmed().endsWith('/')) && (BA.trimmed().size() > 0))
            emit processOutput(BA.trimmed());
    }
}
