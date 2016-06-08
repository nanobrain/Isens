#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "ConnectedSensor.h"
using namespace std;

class ConnectedSensor;

class Command
{
public:
	Command();
	Command(ConnectedSensor *sensor, string t);
	virtual bool exec() = 0;
	virtual const string getName() { return string("undefined command"); }
	virtual const string getDescription() { return string("description is not available"); }
	virtual Command* create(ConnectedSensor *sensor, string t) = 0;
	static vector<string> split(string str, const string& delimiter);

protected:
	vector<string> args; 
	ConnectedSensor *sensor;
};


class CommandEngine
{
public:
	CommandEngine();
	virtual ~CommandEngine();
	virtual void registerCommand(Command *command);
	virtual bool exec(ConnectedSensor *sensor, string t);
	virtual vector<Command*> listCommands();

protected:
	vector <Command*> commands;
};

