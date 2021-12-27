#include "clipserver.h"
#include <QImageReader>

int bytesToInt(QByteArray bytes) {
    int addr = bytes[0] & 0x000000FF;
    addr |= ((bytes[1] << 8) & 0x0000FF00);
    addr |= ((bytes[2] << 16) & 0x00FF0000);
    addr |= ((bytes[3] << 24) & 0xFF000000);
    return addr;
}

QString intToIpv4(unsigned int value) {
    char *addr = new char[15];
    sprintf(addr, "%d.%d.%d.%d",
                (value >> 24) & 0xff,
                (value >> 16) & 0xff,
                (value >> 8)& 0xff,
                (value) & 0xff);
    return QString(addr);
}

ClipServer::ClipServer(QObject *parent) : QObject(parent)
{
    init();
}

void ClipServer::setContentHolder(QTextEdit *textEdit)
{
    this->textEdit = textEdit;
}

ClipServer::~ClipServer()
{
    delete server;
    delete settings;
}

void ClipServer::acceptConnection()
{
    clientConnection = server->nextPendingConnection();
    connect(clientConnection, SIGNAL(readyRead()), this, SLOT(readClient()));
}

void ClipServer::readClient()
{
    recvData();
}

void ClipServer::recvData()
{

    // first recv
    if (dataSize == 0) {
        firstSize =  clientConnection->bytesAvailable();
        dataSize += firstSize;
        QByteArray head = clientConnection->readAll();
        totalSize = bytesToInt(head.mid(0, 4));
        data.append(head.mid(4, head.size() - 4));
        if (totalSize == head.size() - 4) {
            appendToTextEdit();
        }

    } else {
        if (firstSize > clientConnection->bytesAvailable()) {
            // if the revcv is done;
            data.append(clientConnection->readAll());
            appendToTextEdit();
        } else  {
            // not done yet
            dataSize += clientConnection->bytesAvailable();
            data.append(clientConnection->readAll());
        }
    }
}

void ClipServer::appendToTextEdit()
{

    QClipboard* board = QApplication::clipboard();
    QImage image;
    image.loadFromData(data);
    QTextCursor cursor = textEdit->textCursor();

    // set prefix
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString curDate = time.toString("yyyy-MM-dd hh:mm:ss"); //设置显示格式
    QString prefix ;
    prefix.append("[Info] Content From ");
    prefix.append( intToIpv4(clientConnection->peerAddress().toIPv4Address()));
    prefix.append(" at ");
    prefix.append(curDate);
    prefix.append(" :\n");


    if( !image.isNull()) {
        QTextCursor cursor = textEdit->textCursor();
        cursor.insertText(prefix);
        cursor.insertImage(image);
        board->setImage(image);
        cursor.insertText(tr("\n"));
    } else {
        QString content;
        content.fromLocal8Bit(data);
        QString text = content.fromLocal8Bit(data);
        cursor.insertText(prefix);
        cursor.insertText(text);
        board->setText(text);
        cursor.insertText(tr("\n"));
    }
    dataSize = 0;
    firstSize = 0;
    data.clear();
}

void ClipServer::init()
{
    settings = new ClipSettings;
    server = new QTcpServer();
    server->listen(QHostAddress::AnyIPv4, settings->getLocalPort());
    connect(server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
}

