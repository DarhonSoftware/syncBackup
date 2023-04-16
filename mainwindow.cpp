#include "mainwindow.h"
#include <QtGui>
#include <QtQuick>

CMainWindow::CMainWindow(QObject *pObject)
    : QObject(pObject)
{
    init();
}

CMainWindow::~CMainWindow()
{
    end();
}

void CMainWindow::init()
{
    //Set default paramenters
    QSize SizeScreen = QGuiApplication::primaryScreen()->availableSize();
    QSize SizeApp(static_cast<int>(SizeScreen.width() * 0.8),
                  static_cast<int>(SizeScreen.height() * 0.7));

    //Load saved paramters
    QSettings Settings;
    Settings.beginGroup("Geometry");
    QSize Size = Settings.value("size", SizeApp).toSize();
    QPoint Point = Settings
                       .value("pos",
                              QPoint((SizeScreen.width() - SizeApp.width()) / 2,
                                     (SizeScreen.height() - SizeApp.height()) / 2))
                       .toPoint();
    Settings.endGroup();

    //Set properties
    setWidth(Size.width());
    setHeight(Size.height());
    setX(Point.x());
    setY(Point.y());
}

void CMainWindow::end()
{
    //Save parameters
    QSettings Settings;
    Settings.beginGroup("Geometry");
    Settings.setValue("size", QSize(width(), height()));
    Settings.setValue("pos", QPoint(x(), y()));
    Settings.endGroup();
}
