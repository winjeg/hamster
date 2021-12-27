#ifndef UPDATETHREAD_H
#define UPDATETHREAD_H
#include <QThread>


class UpdateThread : public QThread
{

    Q_OBJECT
public:
    UpdateThread();

protected:
    void run();

signals:
    void updateNumber();
    void changeColor();
};

#endif // UPDATETHREAD_H
