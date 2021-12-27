#ifndef CLIPSERVER_H
#define CLIPSERVER_H

#include <QObject>
#include <QtNetwork>
#include <QTextEdit>
#include <QApplication>
#include <QClipboard>
#include <QDateTime>

#include "clipsettings.h"

class ClipServer : public QObject
{
    Q_OBJECT
public:
    explicit ClipServer(QObject *parent = 0);
    void setContentHolder(QTextEdit *textEdit);
    ~ClipServer();

private:
    QTcpServer *server;
    QTcpSocket *clientConnection;
    QTextEdit *textEdit;
    qint64 dataSize = 0;
    qint64 firstSize = 0;
    int totalSize = 0;
    void recvData();
    void appendToTextEdit();
    QByteArray data;
    ClipSettings* settings;

    void init();

signals:

public slots:
        void acceptConnection();
        void readClient();
};

#endif // CLIPSERVER_H
