#include "isense.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ISense w;
    w.show();

    return a.exec();
}
