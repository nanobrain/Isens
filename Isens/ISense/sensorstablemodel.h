#ifndef SENSORSTABLEMODEL_H
#define SENSORSTABLEMODEL_H

#include<QAbstractTableModel>
#include<QDebug>
#include<QVector>
#include<QString>
#include<QList>

enum {
	COL_NAME,
	COL_ID
};

class SensorsTableModel : public QAbstractTableModel
{
public:
	explicit SensorsTableModel(QObject *parent);
	explicit SensorsTableModel(QList< QPair<QString,QString> > pairs, QObject *parent=0);

	QString getStatus(const int pos) const;
	void setStatus(const int pos, QString value) const;
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
	QList< QPair<QString, QString> > listOfPairs;
	signals:
	void editCompleted(const QString &) const;
};

#endif // SENSORSTABLEMODEL_H
