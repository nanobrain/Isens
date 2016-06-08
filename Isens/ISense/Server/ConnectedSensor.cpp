#include "ConnectedSensor.h"

ConnectedSensor::ConnectedSensor(TCPServer* server, int connected_socket, uint32_t ip, uint16_t port)
{
    this->server = server;
    this->connected_socket = connected_socket;
    this->ip = ip;
    this->port = port;
	this->start();
    pthread_create(&thread_id, NULL, run, (void*)this);
}


vector<Command*> ConnectedSensor::listCommands() 
{ 
	return server->listCommands(); 
}

void ConnectedSensor::putline(string str)
{
    send(connected_socket, str.c_str(), str.length(), 0);
}

ConnectedSensor::~ConnectedSensor()
{
    disconnect();
}

void ConnectedSensor::disconnect()
{
    shutdown(connected_socket, SHUT_RDWR);
}

string ConnectedSensor::getline(bool asterisks)
{
    string line("");
    char c;
    size_t rxbytes;
    do {
        rxbytes = recv(connected_socket, &c, 1, 0);
        if(rxbytes == 1 && c>=32)
        {
            line += c;
            if(asterisks) c = '*';
            send(connected_socket, &c, 1, 0); //echo
        }
		if (rxbytes == -1) { this->stop(); throw ::exception("sensor disconnected"); }
    } while (rxbytes==1 && c!='\r');
    return line;
}

void* ConnectedSensor::run(void* arg)
{
    ConnectedSensor * sensor = (ConnectedSensor*)arg;

    sensor->putline("Sensor: ");
    sensor->user = sensor->getline(false);
    cout << sensor->user << endl;

    /*sensor->putline(Common::EOLN + "Pass: ");
    sensor->pass = sensor->getline(true);
    cout << sensor->pass << endl;*/

    string c("");
    do 
	{
        sensor->putline(Common::EOLN + "Cmd: ");
		try {
			c = sensor->getline();
		} 
		catch(exception e)
		{
			sensor->putline(Common::EOLN + e.what());
			break;
		}

        cout << sensor->user << ": " << c << endl;

		try 
		{
			sensor->server->cmdEngine->exec(sensor, c);
		} 
		catch(exception e)
		{
			sensor->putline(Common::EOLN + e.what());
		}
    } while(sensor->is_running());

    sensor->disconnect();
    sensor->server->removeSensor(sensor);
    return NULL;
}
