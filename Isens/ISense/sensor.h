#ifndef SENSOR_H
#define SENSOR_H

//#include "commons.h"
#include <QObject>
#include <QString>

class Sensor : public QObject
{
	Q_OBJECT
public:
	// Constructos
	explicit Sensor(QObject *parent);
	explicit Sensor(QObject *parent,QString a_name,QString a_ID);
	// Copy constructor
	Sensor(QObject *parent, const Sensor& sen);
	// Assignment operator
	Sensor& operator=(const Sensor& right);
	// Compare operator
	bool operator==(const Sensor& right);
	~Sensor();
	QString toString(){return m_name;}
	QString name(){return m_name;}
	QString ID(){return m_ID;}
	QString status(){return m_status;}
	void setName(QString Name){m_name=Name;}
	void setStatus(QString Status){m_status=Status;}
	void setID(QString ID){m_ID=ID;}
private:
	// Members
	QString m_name;
	QString m_ID;
	QString m_status;
signals:

public slots:
};

#endif // SENSOR_H
