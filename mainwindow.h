#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <qqmlintegration.h>

class CMainWindow : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(int width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(int height READ height WRITE setHeight NOTIFY heightChanged)
    Q_PROPERTY(int x READ x WRITE setX NOTIFY xChanged)
    Q_PROPERTY(int y READ y WRITE setY NOTIFY yChanged)

    int m_iWidth;
    int m_iHeight;
    int m_iX;
    int m_iY;

public:
    explicit CMainWindow(QObject *pObject = 0);
    ~CMainWindow();

    void setWidth(int iWidth)
    {
        m_iWidth = iWidth;
        emit widthChanged();
    }
    int width() const { return m_iWidth; }
    void setHeight(int iHeight)
    {
        m_iHeight = iHeight;
        emit heightChanged();
    }
    int height() const { return m_iHeight; }
    void setX(int iX)
    {
        m_iX = iX;
        emit xChanged();
    }
    int x() const { return m_iX; }
    void setY(int iY)
    {
        m_iY = iY;
        emit yChanged();
    }
    int y() const { return m_iY; }

signals:
    void widthChanged();
    void heightChanged();
    void xChanged();
    void yChanged();

private:
    void init();
    void end();
};

#endif // MAINWINDOW_H
