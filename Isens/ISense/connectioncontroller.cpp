#include "connectioncontroller.h"

extern SensorsTableModel* m_sensorsTableModel;

ConnectionController::ConnectionController(QObject *parent) : QObject(parent)
{
	qDebug()<<"Created ConnectionControler"<<endl;
	connect(this,SIGNAL(appendSensorsToTable(Sensor*)),m_sensorsTableModel,SLOT(onAddSensorToTable(Sensor*)));
}

ConnectionController::~ConnectionController()
{
	m_pSocket->write(SERVER_CMD_EXIT);
}

void ConnectionController::connectToServer()
{
	bool reconnect=1;

	m_pSocket= new QTcpSocket(this); // <-- needs to be a member variable: QTcm_pSocket* _pSocket;
	connect( m_pSocket, SIGNAL(readyRead()), SLOT(readTcpData()) );

	while(reconnect)
	{
		m_pSocket->connectToHost("192.168.1.168", 1666); // Server returns: "Sensor:"
		if( m_pSocket->waitForConnected(SERVER_RECONNECT_TIME) )
		{
			//introduceMyself();
			m_pSocket->write(SERVER_CMD_MY_NAME);
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
}

void ConnectionController::disconnectFromServer()
{
	m_pSocket->disconnectFromHost();
}

QVector<QPair<QString,QString>> ConnectionController::getSensorsList()
{
	QPair<QString,QString> List={"",""};
	//QPair<QString,QString> DataVector;

	QByteArray Data = m_pSocket->readAll();
	QString Name = static_cast<QString>(Data);
	List.first=Name;
	List.second="132.132.321.213";

	//DataVector.push_back(List);

	return List;
}
void ConnectionController::listSensors()
{
	/*
	m_pSocket->write(SERVER_CMD_LIST);
	QPair<QString,QString> List = getSensorsList();
	emit appendSensorsToTable(List);
	*/
}

void ConnectionController::readTcpData()
{
	QString result;
	result = static_cast<QString>(m_pSocket->readAll());
	qDebug()<< result.split("\r\n",QString::SkipEmptyParts);
	QPair<QString,QString> list;
	list.first="nazwa";
	list.second="adres";
	//m_sensorsTableModel->addEntry(list);
}

void ConnectionController::introduceMyself(){/**/}
