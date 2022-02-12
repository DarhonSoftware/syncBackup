#include <QtQuick>
#include "about.h"

CAbout::CAbout(QObject *pObject) :  QObject(pObject)
{
  init();
}

CAbout::~CAbout()
{
}

void CAbout::init()
{
  setIconAbout("qrc:/images/about.png");
  setIconBack("qrc:/images/button-back.png");
  setAppName(QString("%1 %2 (Qt - %3)").arg("syncBackup",qApp->applicationVersion(),QT_VERSION_STR));
  setCaption(tr("Backup and mirror your drives"));
  setDescription(tr("It offers the most common options getting most of the power from rsync.")+\
                 "\n"+tr("It takes advantage of the delta-transfer algorithm, which reduces the amount of data sent over the network ")+\
                 tr("by sending only the differences between the source files and the existing files in the destination.")+\
                 "\n"+tr("It finds files that need to be transferred using a 'quick check' algorithm that looks ")+\
                 tr("for files that have changed in size or in last-modified time."));
  setIconDarhon("qrc:/images/darhon.png");
  setCopyright(tr("Copyright 2010-2022 - Darhon Software"));
  setSupport(tr("Help & Support") + " - " + QCoreApplication::organizationDomain());
  setPrivacy(QString("<a href='https://darhon.com/syncbackup-privacy-policy'>%1</a>").arg(tr("Privacy Policy")));
  setVersion("");
}
