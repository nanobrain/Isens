#include "Server.h"

TCPServer::TCPServer()
{
    my_socket = -1;
	_is_running = false;
	cmdEngine = new CommandEngine();
}

TCPServer::~TCPServer()
{
	if(_is_running) stop();
	delete cmdEngine;
}


ConnectedSensor* TCPServer::findSensor(string user)
{
	//vector<ConnectedSensor*>::iterator it;
	for(auto it = sensors.begin(); it != sensors.end(); ++it)
	{
		if((*it)->getUser() == user)
		{
			return *it;
		}
	}
	return NULL;
}

vector<Command*> TCPServer::listCommands() 
{ 
	return cmdEngine->listCommands(); 
}
vector<ConnectedSensor*> TCPServer::listSensors() 
{ 
	return sensors; 
}

void TCPServer::addSensor(ConnectedSensor * sensor)
{
    sensors.push_back(sensor);
}

void TCPServer::removeSensor(ConnectedSensor * sensor)
{
    //vector<ConnectedSensor*>::iterator it;
	for(auto it = sensors.begin(); it != sensors.end(); ++it)
	{
		if(*it == sensor)
		{
			sensors.erase(it);
			delete sensor;
			return;
		}
	}
}

void TCPServer::start(uint16_t port)
{
    this->port = port;
	_is_running = true;
    pthread_create(&thread_id, NULL, run, (void*)this);
}

void TCPServer::stop()
{
    shutdown(my_socket, SHUT_RDWR);
	_is_running = false;
}

bool TCPServer::is_running() 
{ 
	return _is_running; 
}

void* TCPServer::run(void *arg)
{
    cerr << "TCPServer::run" << endl;
    TCPServer *server = (TCPServer *)arg;
   
    server->my_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if( server->my_socket == -1)
    {
		server->stop();
        return NULL;
    }

	sockaddr_in local;
    memset((char*)&local, 0, sizeof(local));
	local.sin_family = AF_INET;
    local.sin_addr.s_addr = htonl(INADDR_ANY);
    local.sin_port = htons(server->port);
    if(bind(server->my_socket, (const sockaddr*)&local, sizeof(local)) == -1)
    {
        cerr << "problem: bind (" << WSAGetLastError() << ")" << endl;
		server->stop();
        return NULL;
    }

    if(listen(server->my_socket, 10) == -1)
    {
        cerr << "problem: listen" << endl;
		server->stop();
        return NULL;
    }

	while(server->is_running()) 
	{
		sockaddr_in remote;
		socklen_t sockaddrlen = sizeof(remote);
        int sensor_socket = accept(server->my_socket, (sockaddr*)&remote, &sockaddrlen);
        if(sensor_socket != -1)
        {
            cout << "sensor connected: "
                << remote.sin_addr.s_addr
                << " : " << remote.sin_port
                << endl;
            server->addSensor(new ConnectedSensor(server, sensor_socket, remote.sin_addr.s_addr, remote.sin_port));
        }
        else
        {
            cout << "accept error." << endl;
			server->stop();
        }
    } 
    return NULL;
}


