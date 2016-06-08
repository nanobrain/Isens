#pragma once
#include "common.h"
#include "ConnectedSensor.h"
#include "Commands.h"

class ConnectedSensor;
class CommandEngine;
class Command;

class TCPServer
{
public:
    TCPServer();
    virtual ~TCPServer();
    virtual void start(uint16_t port);
    virtual void stop();
	virtual bool is_running();
	vector<ConnectedSensor*> listSensors();
	ConnectedSensor* findSensor(string sensor_name);
	//void send_msg_to_sensor(string remote);

protected:	
	friend class ConnectedSensor;
    virtual void addSensor(ConnectedSensor * sensor);
    virtual void removeSensor(ConnectedSensor * sensor);    
	static void* run(void *); 
	CommandEngine *cmdEngine;
	vector<Command*> listCommands();

private:
    int my_socket;
	volatile bool _is_running;
    uint16_t port;
    pthread_t thread_id;
    vector<ConnectedSensor*> sensors;
};

