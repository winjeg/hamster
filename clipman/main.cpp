#include "clipman.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClipMan w;
    w.show();

    return a.exec();
}
