#include <QGuiApplication>
#include <QQuickStyle>
#include <QtQml>
#include "about.h"
#include "backend.h"
#include "mainwindow.h"

#include <QLocale>
#include <QTranslator>

CBackend *g_pBackend;
QString g_sSshAskPass;

int main(int argc, char *argv[])
{
    //Initiate main objects
    QGuiApplication App(argc, argv);

    //Handle arguments
    //- Default '/usr/bin/ssh-askpass'
    g_sSshAskPass = "ssh-askpass";
    for (int i = 0; i < argc; i++) {
        QString s2, s1 = argv[i];
        if (i < argc - 1) {
            s2 = argv[i + 1];
            if (s1 == "--ssh-askpass") {
                g_sSshAskPass = s2;
                i++;
            }
        }
    }

    //Initialise modules
    QQuickStyle::setStyle("Fusion");

    //Set application names
    QCoreApplication::setOrganizationName("Darhon");
    QCoreApplication::setApplicationName("syncBackup");
    QCoreApplication::setApplicationVersion("2.0.1");
    QCoreApplication::setOrganizationDomain("www.darhon.com");

    //Setup translations
    QTranslator Translator;
    QString sLanguage = QLocale::system().name().left(2);
    if (Translator.load(QString("syncbackup_") + sLanguage, ":/i18n"))
        App.installTranslator(&Translator);

    //Register QML Object Types
    qmlRegisterType<CAbout>("com.darhon", 1, 0, "About");
    qmlRegisterType<CMainWindow>("com.darhon", 1, 0, "MainWindow");

    //Initiate Engine
    QQmlApplicationEngine Engine;
    QObject::connect(
        &Engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &App,
        []() { return QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    //Initiate global objects
    g_pBackend = new CBackend(&Engine);

    //Set up context
    Engine.rootContext()->setContextProperty("backend", g_pBackend);

    //Load QML component
    Engine.load(QUrl("qrc:/qt/qml/darhon/qml/main.qml"));
    return App.exec();
}
