#include "eyeprotector.h"
#include "ui_eyeprotector.h"
#include <QDateTime>
#include <QHBoxLayout>
#include <QTimer>
#include <QWidget>
static int i = 40;
static bool ready = false;

EyeProtector::EyeProtector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EyeProtector)
{
    ui->setupUi(this);

    // set window transparent for input and frameless and on top
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    setWindowFlags(windowFlags() | Qt::Tool);
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    setWindowFlags(windowFlags() | Qt::WindowTransparentForInput);


    // set tray icon
    mTrayIcon= new QSystemTrayIcon(this);
    mTrayIcon->setIcon(QIcon(":/icon/icon.ico"));
    mTrayIcon->show();

    // set window color and alpha value
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(0, 20, 220, 180));
    setPalette(pal);

    ui->label_2->setStyleSheet("QLabel {color : white; }");
    ui->label_2->setGeometry(550, 300,  900, 200);
    ui->label->setStyleSheet("QLabel {color : white; }");
    ui->label->setGeometry(650, 400,  600, 200);
    ui->label->setText(tr("Please take a rest..."));

    QTimer *timer = new QTimer(this);
    timer->setInterval( 1000 );
    connect( timer, SIGNAL(timeout()), this, SLOT(updateTime()) );
    timer->start();
    updateTime();

    connect(mTrayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
               this,SLOT(on_trayIcon_activated(QSystemTrayIcon::ActivationReason)));

}

EyeProtector::~EyeProtector()
{
    delete ui;
}

void EyeProtector::updateTime()
{
    //activate the window
    setWindowState(Qt::WindowActive);
    QDateTime now = QDateTime::currentDateTime();//获取系统现在的时间
    long time = now.toMSecsSinceEpoch() / 1000;
    // duration every hour
    if (time % 3600 == 0 ) {
        ready = true;
    }
    if (ready) {
        ++i;
        if (i < 100) {
            setWindowOpacity(i * 0.01);
            show();
        }
        if (i == 100) {
            ready = false;
            hide();
            i = 40;
        }
    } else {
        setWindowOpacity(0.0);
    }

    QString str = now.toString("yyyy-MM-dd hh:mm:ss"); //设置显示格式
    ui->label_2->setText( str );
}


void EyeProtector::on_trayIcon_activated(const QSystemTrayIcon::ActivationReason& reason) {
    switch (reason) {
    case QSystemTrayIcon::DoubleClick:
        exit(0);
    case QSystemTrayIcon::Trigger:
        ready = false;
        hide();
    default:
        break;
    }
}

