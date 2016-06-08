#pragma once

#include "Commands.h"


class CmdTest : public Command
{
public:
	CmdTest(ConnectedSensor *sensor, string t) : Command(sensor, t) { }
	CmdTest() : Command() { }
	Command* create(ConnectedSensor *sensor, string t) { return new CmdTest(sensor, t); }
	const string getName() { return "test"; }
	bool exec();
};



class CmdHelp : public Command
{
public:
	CmdHelp(ConnectedSensor *sensor, string t) : Command(sensor, t) { }
	CmdHelp() : Command() { }
	Command* create(ConnectedSensor *sensor, string t) { return new CmdHelp(sensor, t); }
	const string getName() { return "help"; }
	bool exec();
};

class CmdDummy : public Command
{
public:
	CmdDummy(ConnectedSensor *sensor, string t) : Command(sensor, t) { }
	CmdDummy() : Command() { }
	Command* create(ConnectedSensor *sensor, string t) { return new CmdDummy(sensor, t); }
	const string getName() { return "dummy"; }
	bool exec();
};


class CmdExit : public Command
{
public:
	CmdExit(ConnectedSensor *sensor, string t) : Command(sensor, t) { }
	CmdExit() : Command() { }
	Command* create(ConnectedSensor *sensor, string t) { return new CmdExit(sensor, t); }
	const string getName() { return "exit"; }
	bool exec();
};

class CmdList : public Command
{
public:
	CmdList(ConnectedSensor *sensor, string t) : Command(sensor, t) { }
	CmdList() : Command() { }
	Command* create(ConnectedSensor *sensor, string t) { return new CmdList(sensor, t); }
	const string getName() { return "list"; }
	bool exec();
};

class CmdMsg : public Command
{
public:
	CmdMsg(ConnectedSensor *sensor, string t) : Command(sensor, t) { }
	CmdMsg() : Command() { }
	Command* create(ConnectedSensor *sensor, string t) { return new CmdMsg(sensor, t); }
	const string getName() { return "msg"; }
	//const string getDescription() { return string("usage: <msg> <username> <text to send>"); }
	bool exec();
};

