#ifndef CLIPSETTINGS_H
#define CLIPSETTINGS_H
#include <QSettings>
#include <QString>
#include <QTextCodec>

class ClipSettings
{
public:
    ClipSettings();
    ~ClipSettings();

public:
    QString getRemoteAddr();
    int getRemotePort();
    int getLocalPort();

    void setLocalPort(const int port);
    void setRemotePort(const int port);
    void setRemoteAddr(const QString addr);
    void writeSettings(const int localPort, const QString& remoteAddr, const int remotePort);

private:
    int localPort = 9999;
    int remotePort = 9999;
    QString remoteAddr = "localhost";
    QSettings* settings;

private:
    void init();

};

#endif // CLIPSETTINGS_H
