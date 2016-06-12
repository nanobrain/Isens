#include "isense.h"
//#include "commons.h"
#include <QApplication>
#include "connectioncontroller.h"

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
