#ifndef CONNECTIONCONTROLLER_H
#define CONNECTIONCONTROLLER_H

#include <QAbstractSocket>
#include <QByteArray>
#include <QTcpSocket>
#include <QVector>
//#include "commons.h"
#include "sensor.h"
#include "sensorstablemodel.h"

#define SERVER_CMD_LIST "list\r\n"
#define SERVER_CMD_MY_NAME "QT APP\r\n"
#define SERVER_CMD_EXIT "exit\r\n"
#define SERVER_RECONNECT_TIME 2000

class ConnectionController : public QObject
{
	Q_OBJECT
public:
	explicit ConnectionController(QObject *parent = 0);
	~ConnectionController();
    void connectToServer();
    void disconnectFromServer();
	void listSensors();
	QPair<QString, QString> getSensorsList();
private:
	void introduceMyself();
	QTcpSocket* m_pSocket;

signals:
	void appendSensorstoTable( QVector<Sensor*> );
public slots:
    void readTcpData();
};

#endif // CONNECTIONCONTROLLER_H
