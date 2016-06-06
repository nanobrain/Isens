#ifndef SENSORSTABLEMODEL_H
#define SENSORSTABLEMODEL_H

#include<QAbstractTableModel>
#include<QDebug>

class SensorsTableModel : public QAbstractTableModel
{
public:
	SensorsTableModel(QObject *parent);
	int rowCount(const QModelIndex &parent=QModelIndex()) const;
	int columnCount(const QModelIndex &parent=QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;
private:
	int m_RowCount=1;
	int m_ColumnCount=3;
};

#endif // SENSORSTABLEMODEL_H
