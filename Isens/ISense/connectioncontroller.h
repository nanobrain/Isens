#ifndef CONNECTIONCONTROLLER_H
#define CONNECTIONCONTROLLER_H

#include <QObject>
#include <QPair>
#include <QString>
#include <QAbstractSocket>
#include <QTcpSocket>
#include <QDebug>

class ConnectionController : public QObject
{
	Q_OBJECT
public:
	explicit ConnectionController(QObject *parent = 0);
    void connectToServer();
    void disconnectFromServer();
	QPair<QString,QString> getSensorsList();
private:
    QTcpSocket *pSocket;

signals:
	void updateSensorsList();
public slots:
};

#endif // CONNECTIONCONTROLLER_H
