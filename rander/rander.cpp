#include "rander.h"
#include "ui_rander.h"
#include <iostream>
int getRandom(int max ) {
    return qrand() % max +1;
}


Rander::Rander(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Rander)
{
    ui->setupUi(this);
    mThread = new UpdateThread;
    setFixedSize(this->width(), this->height());
    setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    connect(mThread, SIGNAL(updateNumber()), this, SLOT(updateNumberLabel()));
    connect(mThread, SIGNAL(changeColor()), this, SLOT(changeColor()));
}

Rander::~Rander()
{
    delete ui;
}

void Rander::on_setting_triggered()
{
    QString str = QInputDialog::getText(this, "设置最大值", "请输入最大值", QLineEdit::Normal, "",0, 0, Qt::ImhPreferNumbers);
    if (!str.isEmpty()) {
        mMaxVal = str.toInt(0, 10);
    }
}

void Rander::on_exit_triggered()
{
    exit(0);
}

void Rander::on_pushButton_clicked()
{
    QDateTime currentTime =  QDateTime::currentDateTime();
    qsrand(currentTime.toMSecsSinceEpoch());
    mThread->start();
}

int Rander::mMaxVal = 100;

void Rander::updateNumberLabel() {
    mPa.setColor(QPalette::WindowText, Qt::black);
    ui->number->setPalette(mPa);
    int value = getRandom(mMaxVal);
    std::cout << "value:\t" << value << "\n";
    ui->number->setText(QString::number(value));
}

void Rander::changeColor() {
    mPa.setColor(QPalette::WindowText, Qt::red);
    ui->number->setPalette(mPa);
}


