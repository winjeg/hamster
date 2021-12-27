#include "rander.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Rander w;
    w.show();

    return a.exec();
}
