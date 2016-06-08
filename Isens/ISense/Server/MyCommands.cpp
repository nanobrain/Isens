#include "MyCommands.h"
#include <cassert>

CommandEngine::CommandEngine()
{
	this->registerCommand(new CmdHelp());
	this->registerCommand(new CmdExit());
	this->registerCommand(new CmdList());
	this->registerCommand(new CmdMsg());
	this->registerCommand(new CmdDummy());
	this->registerCommand(new CmdTest());
}


bool CmdTest::exec() 
{ 
	//assert(0);
	sensor->putline("Test OK!");
	return true; 
}


bool CmdDummy::exec() 
{ 
	return true; 
}


bool CmdExit::exec() 
{ 
	sensor->stop(); 
	return true; 
}

bool CmdHelp::exec() 
{  
	vector<Command*> list = sensor->listCommands();
	for(vector<string>::size_type i = 0; i<list.size(); ++i)
		sensor->putline(Common::EOLN + list.at(i)->getName() + " (" + getDescription() + ")" + Common::EOLN);
	return true;
}

bool CmdList::exec()
{
	vector<ConnectedSensor*> sensors = sensor->getServer()->listSensors();
	for(vector<ConnectedSensor*>::size_type i = 0; i<sensors.size(); ++i)
		sensor->putline(Common::EOLN + sensors.at(i)->getUser());
	return true;
}

bool CmdMsg::exec()
{
	if(args.size() < 3) return false;
	ConnectedSensor* remote = sensor->getServer()->findSensor(args.at(1));
	if(remote == NULL) return false;
	remote->putline(Common::EOLN + sensor->getUser() + ": " + args.at(2));
	return true;
}