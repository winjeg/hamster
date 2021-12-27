#include "clipman.h"
#include "ui_clipman.h"


ClipMan::ClipMan(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClipMan)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Tool);
    setGeometry(300, 200, 940, 633);

    systemTray = new QSystemTrayIcon();
    systemTray ->setToolTip(QString("Clipman: click to show, click to hide.\nDouble Click to exit"));
    systemTray ->setIcon(QIcon(":/imgs/icon.png"));
    connect(systemTray , SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(iconIsActived(QSystemTrayIcon::ActivationReason)));

    aboutDialog = new AboutDialog(this);
    settingsDialog =  new SettingDialog(this);
    manager =  new ClipBoardManager(this);
    server = new ClipServer(this);
    server->setContentHolder(ui->textEdit);
    client = new ClipClient(this);

    systemTray->show();

}


ClipMan::~ClipMan()
{
    delete ui;
}

void ClipMan::on_action_Quit_triggered()
{
    QApplication::quit();
}

void ClipMan::on_action_Clipboard_triggered()
{
     manager->appendClipBoardTo(ui->textEdit);
}

void ClipMan::on_action_About_Me_triggered()
{
    aboutDialog->show();
}

void ClipMan::on_action_Settings_triggered()
{
    settingsDialog->show();
}

void ClipMan::iconIsActived(QSystemTrayIcon::ActivationReason reason)
{
    if(reason == QSystemTrayIcon::DoubleClick) {
        QApplication::quit();
    } else {
        this->show();
    }
}

void ClipMan::on_sendBtn_clicked()
{
    const QClipboard* board = manager->getClipBoard();
    QImage image = board->image();
    QString textOnBoard;
    if (image.isNull()) {
        textOnBoard = board->text();
        QByteArray data = textOnBoard.toLocal8Bit();
        client->sendDataToAddress(data);
    } else {
        QByteArray arr;
        QBuffer buffer(&arr);
        buffer.open(QIODevice::ReadWrite);
        image.save(&buffer,"png");
        buffer.close();
        client->sendDataToAddress(arr);
    }
}

void ClipMan::on_clearBtn_clicked()
{
     ui->textEdit->clear();
}
