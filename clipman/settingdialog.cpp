#include "settingdialog.h"
#include "ui_settingdialog.h"

SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);
    settings =  new ClipSettings;
    ui->localLineEdit->setText(QString::number(settings->getLocalPort()));
    ui->remoteAddrEdit->setText(settings->getRemoteAddr());
    ui->remotePortEdit->setText(QString::number(settings->getRemotePort()));
}

SettingDialog::~SettingDialog()
{
    delete settings;
    delete ui;
}

void SettingDialog::on_okBtn_clicked()
{
    int localPort = ui->localLineEdit->text().toInt();
    int remotePort = ui->remotePortEdit->text().toInt();
    QString remoteAddr = ui->remoteAddrEdit->text();
    settings->writeSettings(localPort, remoteAddr, remotePort);
    this->hide();
}
