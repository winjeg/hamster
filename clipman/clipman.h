#ifndef CLIPMAN_H
#define CLIPMAN_H

#include <QMainWindow>
#include <QSystemTrayIcon>


#include "clipboardmanager.h"
#include "clipclient.h"
#include "clipserver.h"
#include "about.h"
#include "settingdialog.h"

namespace Ui {
class ClipMan;
}

class ClipMan : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClipMan(QWidget *parent = 0);
    ~ClipMan();

private slots:
    void on_action_Quit_triggered();

    void on_action_Clipboard_triggered();

    void on_sendBtn_clicked();

    void on_clearBtn_clicked();

    void on_action_About_Me_triggered();

    void on_action_Settings_triggered();

    void iconIsActived(QSystemTrayIcon::ActivationReason reason);

private:
    Ui::ClipMan *ui;
    ClipBoardManager * manager;
    ClipClient * client;
    ClipServer * server;
    AboutDialog * aboutDialog;
    SettingDialog* settingsDialog;
    QSystemTrayIcon *systemTray;

};

#endif // CLIPMAN_H
