#include "eyeprotector.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EyeProtector w;
    w.hide();
    w.show();
    return a.exec();
}
