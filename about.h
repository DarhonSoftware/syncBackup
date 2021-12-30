#ifndef ABOUT_H
#define ABOUT_H

#include <QObject>
#include <QString>

class CAbout : public QObject
{
  Q_OBJECT

  Q_PROPERTY(QString iconAbout READ iconAbout WRITE setIconAbout NOTIFY iconAboutChanged)
  Q_PROPERTY(QString iconBack READ iconBack WRITE setIconBack NOTIFY iconBackChanged)
  Q_PROPERTY(QString appName READ appName WRITE setAppName NOTIFY appNameChanged)
  Q_PROPERTY(QString version READ version WRITE setVersion NOTIFY versionChanged)
  Q_PROPERTY(QString caption READ caption WRITE setCaption NOTIFY captionChanged)
  Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
  Q_PROPERTY(QString iconDarhon READ iconDarhon WRITE setIconDarhon NOTIFY iconDarhonChanged)
  Q_PROPERTY(QString copyright READ copyright WRITE setCopyright NOTIFY copyrightChanged)
  Q_PROPERTY(QString support READ support WRITE setSupport NOTIFY supportChanged)
  Q_PROPERTY(QString privacy READ privacy WRITE setPrivacy NOTIFY privacyChanged)

  QString m_sIconAbout;
  QString m_sIconBack;
  QString m_sAppName;
  QString m_sVersion;
  QString m_sCaption;
  QString m_sDescription;
  QString m_sIconDarhon;
  QString m_sCopyright;
  QString m_sSupport;
  QString m_sPrivacy;

public:
  explicit CAbout(QObject *pObject=0);
  ~CAbout();

  void setIconAbout(const QString &sIconAbout) {m_sIconAbout=sIconAbout; emit iconAboutChanged();}
  QString iconAbout() const {return m_sIconAbout;}
  void setIconBack(const QString &sIconBack) {m_sIconBack=sIconBack; emit iconBackChanged();}
  QString iconBack() const {return m_sIconBack;}
  void setAppName(const QString &sAppName) {m_sAppName=sAppName; emit appNameChanged();}
  QString appName() const {return m_sAppName;}
  void setVersion(const QString &sVersion) {m_sVersion=sVersion; emit versionChanged();}
  QString version() const {return m_sVersion;}
  void setCaption(const QString &sCaption) {m_sCaption=sCaption; emit captionChanged();}
  QString caption() const {return m_sCaption;}
  void setDescription(const QString &sDescription) {m_sDescription=sDescription; emit descriptionChanged();}
  QString description() const {return m_sDescription;}
  void setIconDarhon(const QString &sIconDarhon) {m_sIconDarhon=sIconDarhon; emit iconDarhonChanged();}
  QString iconDarhon() const {return m_sIconDarhon;}
  void setCopyright(const QString &sCopyright) {m_sCopyright=sCopyright; emit copyrightChanged();}
  QString copyright() const {return m_sCopyright;}
  void setSupport(const QString &sSupport) {m_sSupport=sSupport; emit supportChanged();}
  QString support() const {return m_sSupport;}
  void setPrivacy(const QString &sPrivacy) {m_sPrivacy=sPrivacy; emit privacyChanged();}
  QString privacy() const {return m_sPrivacy;}

signals:
  void iconAboutChanged();
  void iconBackChanged();
  void appNameChanged();
  void versionChanged();
  void captionChanged();
  void descriptionChanged();
  void iconDarhonChanged();
  void copyrightChanged();
  void supportChanged();
  void privacyChanged();

private:

public slots:
  void init();
};

#endif // ABOUT_H
