#include "isense.h"
#include "connectioncontroller.h"

ConnectionController::ConnectionController(QObject *parent) : QObject(parent)
{
	qDebug()<<"Created ConnectionControler"<<endl;
}

ConnectionController::~ConnectionController()
{
	pSocket->write(SERVER_CMD_EXIT);
	delete m_connectionController;
	m_connectionController=0;
}

void ConnectionController::connectToServer()
{
	bool reconnect=1;
	connect(m_connectionController,SIGNAL(updateSensorsList(QPair<QString,QString>)),m_sensorsTableModel,SLOT(onAddSensorToTable(QPair<QString,QString>)));

    pSocket = new QTcpSocket(this); // <-- needs to be a member variable: QTcpSocket * _pSocket;
    connect( pSocket, SIGNAL(readyRead()), SLOT(readTcpData()) );

	while(reconnect)
	{
		pSocket->connectToHost("192.168.1.168", 1666); // Server returns: "Sensor:"
		if( pSocket->waitForConnected(SERVER_RECONNECT_TIME) )
		{
			//introduceYourself();
			pSocket->write(SERVER_CMD_MY_NAME);
			reconnect=0;
		}
		else
			{
				if( QMessageBox::information(0,"Server error",
											 "Cannot connect to server. Retry?",
											 QMessageBox::Yes|QMessageBox::No) == QMessageBox::No)
					reconnect=0;
			}
	}
	listSensors();
}

void ConnectionController::disconnectFromServer()
{
    pSocket->disconnectFromHost();
}

QVector<QPair<QString,QString>> ConnectionController::getSensorsList()
{
	QPair<QString,QString> List={"",""};
	QVector<QPair<QString,QString>> DataVector;

	QByteArray Data = pSocket->readAll();
	QString Name = static_cast<QString>(Data);
	List.first=Name;
	List.second="132.132.321.213";

	DataVector.push_back(List);

	return DataVector;
}
void ConnectionController::listSensors()
{
	pSocket->write(SERVER_CMD_LIST);
	//QVecotr<QPair<QString,QString>> List = getSensorsList();
	//emit updateSensorsList(List);
}

void ConnectionController::readTcpData()
{
	QString result;
	result = static_cast<QString>(pSocket->readAll());
	qDebug()<< result.split("\r\n",QString::SkipEmptyParts);
}
void ConnectionController::introduceYourself(){/**/}
