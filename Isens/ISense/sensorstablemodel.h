#ifndef SENSORSTABLEMODEL_H
#define SENSORSTABLEMODEL_H

#include "sensor.h"
//#include "commons.h"
#include <QAbstractTableModel>
#include <QMessageBox>
#include <QDebug>

enum {
	COL_NAME,
	COL_IP
};

class SensorsTableModel : public QAbstractTableModel
{
	Q_OBJECT
public:
	explicit SensorsTableModel(QObject *parent);
	explicit SensorsTableModel(QObject *parent, QVector<Sensor*> vecSen);
	~SensorsTableModel();

	QString getStatus(const int pos) const;
	void setStatus(const int pos, QString value) const;
	void addEntry(Sensor* sen);
	void addEntries(QVector<Sensor*> vSensors);
	// Overloads // TODO: ADD THIS INFORMATION IN OTHER HEADERS
	/****************************************/
	int rowCount(const QModelIndex &parent=QModelIndex()) const Q_DECL_OVERRIDE;
	int columnCount(const QModelIndex &parent=QModelIndex()) const Q_DECL_OVERRIDE;
	bool insertRows(int position, int rows, const QModelIndex &index=QModelIndex()) Q_DECL_OVERRIDE;
	bool removeRows(int position, int rows, const QModelIndex &index=QModelIndex()) Q_DECL_OVERRIDE;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;
	bool setData(const QModelIndex &index, const QVariant &value, int role) Q_DECL_OVERRIDE;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
	Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
	/****************************************/
	QVector<Sensor*> getList();
private:
	QVector<Sensor*> m_SensorList;

signals:
	void editCompleted(const QString &) const;

public slots:
	void onAddSensorToTable(Sensor* sen);
	void onAddSensorsToTable(QVector<Sensor*> vSen);
	void onUpdateSensorList();
};

#endif // SENSORSTABLEMODEL_H
