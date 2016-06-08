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
    QPair<QString,QString> data = pSocket->readAll();
    return data;
}

void updateSensorsList()
{

}
