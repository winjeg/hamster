#ifndef CLIPMANCLIENT_H
#define CLIPMANCLIENT_H

#include <QObject>
#include <QtNetwork>
#include <clipsettings.h>

 class ClipClient : public QObject
{
    Q_OBJECT
public:
    explicit ClipClient(QObject *parent = 0);
    void sendDataToAddress(const QByteArray& data);

private:
    QTcpSocket *client;
    ClipSettings * settings;
    QString address;
    int port;
    void init();

signals:

public slots:
};

#endif // CLIPMANCLIENT_H
