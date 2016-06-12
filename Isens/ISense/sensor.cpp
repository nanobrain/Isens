#include "sensor.h"

Sensor::Sensor(QObject *parent)
	: QObject(parent),
	  m_name("Default name"),
	  m_ID("Default ID"),
	  m_status("Not connected")
{
/**/
}

Sensor::Sensor(QObject *parent, QString a_name, QString a_ID)
	: QObject(parent),
	  m_name(a_name),
	  m_ID(a_ID),
	  m_status("Not connected")
{
/**/
}

Sensor::Sensor(QObject *parent, const Sensor& sen)
	: QObject(parent)
{
	this->m_name=sen.m_name;
	this->m_ID=sen.m_ID;
	this->m_status=sen.m_status;
}

Sensor& Sensor::operator=(const Sensor& right)
{
	this->m_name=right.m_name;
	this->m_ID=right.m_ID;
	this->m_status=right.m_status;

	return *this;
}

bool Sensor::operator==(const Sensor& right)
{
	if(m_ID == right.m_ID)
		return true;
	else
		return false;
}

Sensor::~Sensor()
{
/**/
}
