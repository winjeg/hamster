#include "updatethread.h"
#define SLEEP_SND 30
#define SLEEP_DUR 100
#define SLOW_NUM 8

UpdateThread::UpdateThread()
{

}

void UpdateThread::run() {
    int i = 0;
    for (; i < SLEEP_SND; ++i) {
        msleep(SLEEP_DUR);
        emit updateNumber();
    }
    i =1;
    while (i < SLOW_NUM) {
        msleep(i * SLEEP_DUR);
        emit updateNumber();
        ++i;
    }
    emit changeColor();
}

