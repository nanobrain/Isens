#include "connectioncontroller.h"

ConnectionController::ConnectionController(QObject *parent) : QObject(parent)
{
}

void ConnectionController::connectToServer()
{
    QByteArray data; // <-- fill with data

    pSocket = new QTcpSocket(this); // <-- needs to be a member variable: QTcpSocket * _pSocket;
    connect( pSocket, SIGNAL(readyRead()), SLOT(readTcpData()) );

    pSocket->connectToHost("127.1.1.1", 1666);
    if( pSocket->waitForConnected() ) {
        pSocket->write( data );
    }
}

void ConnectionController::disconnectFromServer()
{
    pSocket->disconnectFromHost();
}

QPair<QString,QString> ConnectionController::getSensorsList()
{
<<<<<<< HEAD
    QPair<QString,QString> list={"",""};
    //QByteArraydata = pSocket->readAll();

    return list;
=======
	QPair<QString,QString> list={"",""};
	//QByteArray data = pSocket->readAll();

	return list;
>>>>>>> b40d5559516a1d460e3e7d05acf883c5860ed248
}

void ConnectionController::readTcpData()
{
/* Read data */
}
