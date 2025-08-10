#ifndef CBACKEND_H
#define CBACKEND_H

#include <QObject>
#include <QProcess>
#include <QQmlApplicationEngine>
#include <QStringListModel>
#include "dr_tools/dr_standarditemmodel.h"

class QCloseEvent;

class CBackend : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool group READ group WRITE setGroup NOTIFY groupChanged)
    Q_PROPERTY(bool owner READ owner WRITE setOwner NOTIFY ownerChanged)
    Q_PROPERTY(bool perms READ perms WRITE setPerms NOTIFY permsChanged)
    Q_PROPERTY(bool links READ links WRITE setLinks NOTIFY linksChanged)
    Q_PROPERTY(bool update READ update WRITE setUpdate NOTIFY updateChanged)
    Q_PROPERTY(bool del READ del WRITE setDel NOTIFY delChanged)
    Q_PROPERTY(bool deleteExcluded READ deleteExcluded WRITE setDeleteExcluded NOTIFY deleteExcludedChanged)
    Q_PROPERTY(bool ignoreNonExisting READ ignoreNonExisting WRITE setIgnoreNonExisting NOTIFY ignoreNonExistingChanged)
    Q_PROPERTY(bool ignoreExisting READ ignoreExisting WRITE setIgnoreExisting NOTIFY ignoreExistingChanged)
    Q_PROPERTY(bool recursive READ recursive WRITE setRecursive NOTIFY recursiveChanged)
    Q_PROPERTY(bool maxSize READ maxSize WRITE setMaxSize NOTIFY maxSizeChanged)
    Q_PROPERTY(quint32 maxSizeValue READ maxSizeValue WRITE setMaxSizeValue NOTIFY maxSizeValueChanged)
    Q_PROPERTY(quint32 unit READ unit WRITE setUnit NOTIFY unitChanged)
    Q_PROPERTY(QString from READ from WRITE setFrom NOTIFY fromChanged)
    Q_PROPERTY(QString to READ to WRITE setTo NOTIFY toChanged)
    Q_PROPERTY(QString fromPort READ fromPort WRITE setFromPort NOTIFY fromPortChanged)
    Q_PROPERTY(QString toPort READ toPort WRITE setToPort NOTIFY toPortChanged)

    Q_PROPERTY(QString confFileName READ confFileName WRITE setConfFileName NOTIFY confFileNameChanged)
    Q_PROPERTY(QString errorMessage READ errorMessage WRITE setErrorMessage NOTIFY errorMessageChanged)
    Q_PROPERTY(bool isRunning READ isRunning WRITE setIsRunning NOTIFY isRunningChanged)
    Q_PROPERTY(QString excIncHelp READ excIncHelp WRITE setExcIncHelp NOTIFY excIncHelpChanged)
    Q_PROPERTY(QString help READ help WRITE setHelp NOTIFY helpChanged)

    bool m_bGroup;
    bool m_bOwner;
    bool m_bPerms;
    bool m_bLinks;
    bool m_bUpdate;
    bool m_bDel;
    bool m_bDeleteExcluded;
    bool m_bIgnoreNonExisting;
    bool m_bIgnoreExisting;
    bool m_bRecursive;
    bool m_bMaxSize;
    quint32 m_iMaxSizeValue;
    quint32 m_iUnit;
    QString m_sFrom;
    QString m_sTo;
    QString m_sFromPort;
    QString m_sToPort;

    QString m_sConfFileName;
    QString m_sErrorMessage;
    bool m_bIsRunning;
    QString m_sExcIncHelp;
    QString m_sHelp;

    QQmlApplicationEngine *m_pEngine;
    CStandardItemModel m_ModelExc;
    CStandardItemModel m_ModelInc;
    QProcess m_Process;

    QStringList m_lsUnits = {"Bytes", "KB", "MB", "GB"};

public:
    explicit CBackend(QQmlApplicationEngine *pEngine = nullptr);
    ~CBackend();

    bool group() const { return m_bGroup; }
    void setGroup(bool bGroup)
    {
        if (m_bGroup == bGroup)
            return;
        m_bGroup = bGroup;
        emit groupChanged();
    }
    bool owner() const { return m_bOwner; }
    void setOwner(bool bOwner)
    {
        if (m_bOwner == bOwner)
            return;
        m_bOwner = bOwner;
        emit ownerChanged();
    }
    bool perms() const { return m_bPerms; }
    void setPerms(bool bPerms)
    {
        if (m_bPerms == bPerms)
            return;
        m_bPerms = bPerms;
        emit permsChanged();
    }
    bool links() const { return m_bLinks; }
    void setLinks(bool bLinks)
    {
        if (m_bLinks == bLinks)
            return;
        m_bLinks = bLinks;
        emit linksChanged();
    }
    bool update() const { return m_bUpdate; }
    void setUpdate(bool bUpdate)
    {
        if (m_bUpdate == bUpdate)
            return;
        m_bUpdate = bUpdate;
        emit updateChanged();
    }
    bool del() const { return m_bDel; }
    void setDel(bool bDel)
    {
        if (m_bDel == bDel)
            return;
        m_bDel = bDel;
        emit delChanged();
    }
    bool deleteExcluded() const { return m_bDeleteExcluded; }
    void setDeleteExcluded(bool bDeleteExcluded)
    {
        if (m_bDeleteExcluded == bDeleteExcluded)
            return;
        m_bDeleteExcluded = bDeleteExcluded;
        emit deleteExcludedChanged();
    }
    bool ignoreNonExisting() const { return m_bIgnoreNonExisting; }
    void setIgnoreNonExisting(bool bIgnoreNonExisting)
    {
        if (m_bIgnoreNonExisting == bIgnoreNonExisting)
            return;
        m_bIgnoreNonExisting = bIgnoreNonExisting;
        emit ignoreNonExistingChanged();
    }
    bool ignoreExisting() const { return m_bIgnoreExisting; }
    void setIgnoreExisting(bool bIgnoreExisting)
    {
        if (m_bIgnoreExisting == bIgnoreExisting)
            return;
        m_bIgnoreExisting = bIgnoreExisting;
        emit ignoreExistingChanged();
    }
    bool recursive() const { return m_bRecursive; }
    void setRecursive(bool bRecursive)
    {
        if (m_bRecursive == bRecursive)
            return;
        m_bRecursive = bRecursive;
        emit recursiveChanged();
    }
    bool maxSize() const { return m_bMaxSize; }
    void setMaxSize(bool bMaxSize)
    {
        if (m_bMaxSize == bMaxSize)
            return;
        m_bMaxSize = bMaxSize;
        emit maxSizeChanged();
    }
    quint32 maxSizeValue() const { return m_iMaxSizeValue; }
    void setMaxSizeValue(quint32 iMaxSizeValue)
    {
        if (m_iMaxSizeValue == iMaxSizeValue)
            return;
        m_iMaxSizeValue = iMaxSizeValue;
        emit maxSizeValueChanged();
    }
    quint32 unit() const { return m_iUnit; }
    void setUnit(quint32 iUnit)
    {
        if (m_iUnit == iUnit)
            return;
        m_iUnit = iUnit;
        emit unitChanged();
    }
    QString from() const { return m_sFrom; }
    void setFrom(const QString &sFrom)
    {
        if (m_sFrom == sFrom)
            return;
        m_sFrom = sFrom;
        emit fromChanged();
    }
    QString to() const { return m_sTo; }
    void setTo(const QString &sTo)
    {
        if (m_sTo == sTo)
            return;
        m_sTo = sTo;
        emit toChanged();
    }
    QString fromPort() const { return m_sFromPort; }
    void setFromPort(const QString &sFromPort)
    {
        if (m_sFromPort == sFromPort)
            return;
        m_sFromPort = sFromPort;
        emit fromPortChanged();
    }
    QString toPort() const { return m_sToPort; }
    void setToPort(const QString &sToPort)
    {
        if (m_sToPort == sToPort)
            return;
        m_sToPort = sToPort;
        emit toPortChanged();
    }

    QString confFileName() const { return m_sConfFileName; }
    void setConfFileName(const QString &sConfFileName)
    {
        if (m_sConfFileName == sConfFileName)
            return;
        m_sConfFileName = sConfFileName;
        emit confFileNameChanged();
    }
    QString errorMessage() const { return m_sErrorMessage; }
    void setErrorMessage(const QString &sErrorMessage)
    {
        if (m_sErrorMessage == sErrorMessage)
            return;
        m_sErrorMessage = sErrorMessage;
        emit errorMessageChanged();
    }
    bool isRunning() const { return m_bIsRunning; }
    void setIsRunning(bool bIsRunning)
    {
        if (m_bIsRunning == bIsRunning)
            return;
        m_bIsRunning = bIsRunning;
        emit isRunningChanged();
    }
    QString excIncHelp() const { return m_sExcIncHelp; }
    void setExcIncHelp(const QString &sExcIncHelp)
    {
        if (m_sExcIncHelp == sExcIncHelp)
            return;
        m_sExcIncHelp = sExcIncHelp;
        emit excIncHelpChanged();
    }
    QString help() const { return m_sHelp; }
    void setHelp(const QString &sHelp)
    {
        if (m_sHelp == sHelp)
            return;
        m_sHelp = sHelp;
        emit helpChanged();
    }

signals:
    void groupChanged();
    void ownerChanged();
    void permsChanged();
    void linksChanged();
    void updateChanged();
    void delChanged();
    void deleteExcludedChanged();
    void ignoreNonExistingChanged();
    void ignoreExistingChanged();
    void recursiveChanged();
    void maxSizeChanged();
    void maxSizeValueChanged();
    void unitChanged();
    void fromChanged();
    void toChanged();
    void fromPortChanged();
    void toPortChanged();

    void confFileNameChanged();
    void errorMessageChanged();
    void isRunningChanged();
    void excIncHelpChanged();
    void helpChanged();

    void processOutput(const QString &sOutput);

public slots:
    bool saveConfiguration(const QString &sFile);
    bool loadConfiguration(const QString &sFile);
    void resetConfiguration();
    void addInclude(const QString &sPath);
    void addExclude(const QString &sPath);
    void removeInclude(int iRow);
    void removeExclude(int iRow);

    void errorProcess(QProcess::ProcessError iError);
    void startedProcess();
    void finishedProcess(int iExitCode, QProcess::ExitStatus iExitStatus);
    void readProcess();

    void init();
    void end();
    void parseArguments(QStringList *plsArguments);
    bool run(bool bDryRun);
    void cancel();
    QString exportCommandLine();
    void copyToClipboard(const QString &s);
    QString displayConfFileName(const QString &s);
    QString translatePathfromQML(const QString &s, bool bFile = true);

private:
    QStringList modelToStringList(QStandardItemModel *pModel);
    void stringListToModel(const QStringList &StringList, QStandardItemModel *pModel);
};

#endif // CBACKEND_H
