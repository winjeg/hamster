#include "about.h"
#include "ui_about.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::on_okBtn_clicked()
{
    this->hide();
}
