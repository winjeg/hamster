#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>
#include "clipsettings.h"

namespace Ui {
class SettingDialog;
}

class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingDialog(QWidget *parent = 0);
    ~SettingDialog();

private slots:
    void on_okBtn_clicked();

private:
    Ui::SettingDialog *ui;
    ClipSettings* settings;
};

#endif // SETTINGDIALOG_H
