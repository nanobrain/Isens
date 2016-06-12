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
		m_pSocket->connectToHost("127.1.1.1", 1666); // Server returns: "Sensor:"
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

QVector<Sensor*> ConnectionController::getSensorsList()
{
	QVector<Sensor*> vecSen;

	QByteArray Data = m_pSocket->readAll();
	QString Name = static_cast<QString>(Data);
	Sensor* sen= new Sensor(0,Name,"Default ID");
	vecSen.push_back(sen);

	return vecSen;
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
	// TODO: ADD SENSORS TO TABLE MODEL
	QVector<Sensor*> vecSen;
	m_sensorsTableModel->addEntries(vecSen);
}

void ConnectionController::introduceMyself(){/**/}
