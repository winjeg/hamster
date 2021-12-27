#include "clipsettings.h"

ClipSettings::ClipSettings()
{
    init();
}

ClipSettings::~ClipSettings()
{

}

QString ClipSettings::getRemoteAddr()
{
    return remoteAddr;
}

int ClipSettings::getRemotePort()
{
    return remotePort;
}

int ClipSettings::getLocalPort()
{
    return localPort;
}

void ClipSettings::setLocalPort(const int port)
{
    localPort = port;
}

void ClipSettings::setRemotePort(const int port)
{
    remotePort = port;
}

void ClipSettings::setRemoteAddr(const QString addr)
{
    remoteAddr = addr;
}

void ClipSettings::writeSettings(const int localPort, const QString &remoteAddr, const int remotePort)
{
    settings =  new QSettings(".clipman",QSettings::IniFormat);
    settings->setIniCodec(QTextCodec::codecForName("UTF-8"));
    settings->beginGroup("local");
    settings->setValue("port", localPort);
    settings->endGroup();

    settings->beginGroup("remote");
    settings->setValue("addr", remoteAddr);
    settings->setValue("port", remotePort);
    settings->endGroup();
}

void ClipSettings::init()
{
     settings =  new QSettings(".clipman",QSettings::IniFormat);
     settings->setIniCodec(QTextCodec::codecForName("UTF-8"));
     settings->beginGroup("local");
     localPort = settings->value("port").toInt();
     settings->endGroup();

     settings->beginGroup("remote");
     remoteAddr  = settings->value("addr").toString();
     remotePort = settings->value("port").toInt();
     settings->endGroup();
}


