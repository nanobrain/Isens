#include "isense.h"
#include <QApplication>

SensorsTableModel *m_sensorsTableModel=0;
ConnectionController *m_connectionController=0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ISense w;
    w.show();

	m_connectionController = new ConnectionController();
	m_connectionController->connectToServer();

    return a.exec();
}
