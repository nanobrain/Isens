#include "isense.h"
#include "connectioncontroller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ISense w;
    w.show();
    ConnectionController c;
    c.connectToServer();

    return a.exec();
}
