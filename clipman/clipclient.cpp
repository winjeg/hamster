#include "clipclient.h"

QByteArray  intToByte(int number)
{
    QByteArray abyte0;
    abyte0.resize(4);
    abyte0[0] = (uchar)  (0x000000ff & number);
    abyte0[1] = (uchar) ((0x0000ff00 & number) >> 8);
    abyte0[2] = (uchar) ((0x00ff0000 & number) >> 16);
    abyte0[3] = (uchar) ((0xff000000 & number) >> 24);
    return abyte0;
}


ClipClient::ClipClient(QObject *parent) : QObject(parent)
{
    init();
}

void ClipClient::sendDataToAddress(const QByteArray& data)
{
    if (!client->isOpen()) {
       client->connectToHost(QHostAddress(address), port);
    }

    int dataSize = data.size();
    int dataWritten = 0;
    int dataOnce = 0;
    client->write(intToByte(dataSize));

    while (dataOnce != -1 && dataWritten < dataSize) {
        dataOnce = client->write(data.mid(dataWritten, dataSize - dataWritten));
        dataWritten += dataOnce;
        if (dataWritten >= dataSize) {
            break;
        }
    }
}

void ClipClient::init()
{
    settings = new ClipSettings;
    this->port = settings->getRemotePort();
    this->address = settings->getRemoteAddr();
    client = new QTcpSocket(this);
}
