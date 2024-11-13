#include <QApplication>
#include <QQuickStyle>
#include <QtQml>
#include "backend.h"

#include <QLocale>
#include <QTranslator>

CBackend *g_pBackend;

int main(int argc, char *argv[])
{
    //Initiate main objects
    QApplication App(argc, argv);

    //Initialise modules
    QQuickStyle::setStyle("Fusion");

    //Set application names
    QCoreApplication::setOrganizationName("darhon");
    QCoreApplication::setApplicationName("syncBackup");
    QCoreApplication::setApplicationVersion("2.1.3");
    QCoreApplication::setOrganizationDomain("darhon.com");

    //Setup translations
    QTranslator Translator;
    if (Translator.load(QLocale(), "syncbackup", "_", ":/i18n")) {
        App.installTranslator(&Translator);
    }

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
    Engine.load(QUrl("qrc:/darhon/qml/mainwindow.qml"));
    return App.exec();
}
