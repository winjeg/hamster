#ifndef RANDER_H
#define RANDER_H

#include <QMainWindow>
#include <QInputDialog>
#include <QDateTime>
#include <QPalette>

#include "updatethread.h"



namespace Ui {
class Rander;
}

class Rander : public QMainWindow
{
    Q_OBJECT

public:
    explicit Rander(QWidget *parent = 0);
    ~Rander();

private slots:
    void on_setting_triggered();

    void on_exit_triggered();

    void on_pushButton_clicked();

private:
    Ui::Rander *ui;
    UpdateThread* mThread;
    QPalette mPa;
    static int mMaxVal;

public slots:
    void updateNumberLabel();
    void changeColor();

};

#endif // RANDER_H
