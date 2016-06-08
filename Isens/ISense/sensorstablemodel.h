#ifndef SENSORSTABLEMODEL_H
#define SENSORSTABLEMODEL_H

#include <QAbstractTableModel>
#include <QMessageBox>
#include <QDebug>
#include <QVector>
#include <QString>
#include <QList>
#include <QPair>

enum {
	COL_NAME,
	COL_IP
};

class SensorsTableModel : public QAbstractTableModel
{
	Q_OBJECT
public:
	explicit SensorsTableModel(QObject *parent);
	explicit SensorsTableModel(QList< QPair<QString,QString> > pairs, QObject *parent=0);
	~SensorsTableModel();

	QString getStatus(const int pos) const;
	void setStatus(const int pos, QString value) const;
	void addEntry(QPair<QString,QString> NewPair);
	int rowCount(const QModelIndex &parent=QModelIndex()) const Q_DECL_OVERRIDE;
	int columnCount(const QModelIndex &parent=QModelIndex()) const Q_DECL_OVERRIDE;
	bool insertRows(int position, int rows, const QModelIndex &index=QModelIndex()) Q_DECL_OVERRIDE;
	bool removeRows(int position, int rows, const QModelIndex &index=QModelIndex()) Q_DECL_OVERRIDE;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;
	bool setData(const QModelIndex &index, const QVariant &value, int role) Q_DECL_OVERRIDE;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
	Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;

	QList< QPair<QString, QString> > getList();
private:
	QList< QPair<QString, QString> > m_listOfPairs;

signals:
	void editCompleted(const QString &) const;

public slots:
	void onAddSensorToTable(QPair<QString,QString> pair);
	void onUpdateSensorList();
};

#endif // SENSORSTABLEMODEL_H
