#ifndef EYEPROTECTOR_H
#define EYEPROTECTOR_H

#include <QDialog>
#include <QPalette>
#include<QSystemTrayIcon>
namespace Ui {
class EyeProtector;
}

class EyeProtector : public QDialog
{
    Q_OBJECT

public:
    explicit EyeProtector(QWidget *parent = 0);
    ~EyeProtector();


private slots:
  void updateTime();
  void on_trayIcon_activated( const QSystemTrayIcon::ActivationReason& reason);

private:
    Ui::EyeProtector *ui;
    QSystemTrayIcon* mTrayIcon;
};

#endif // EYEPROTECTOR_H
