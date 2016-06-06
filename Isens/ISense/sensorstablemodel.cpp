#include "sensorstablemodel.h"

SensorsTableModel::SensorsTableModel(QObject *parent)
	:QAbstractTableModel(parent)
{}

SensorsTableModel::rowCount(const QModelIndex &parent) const
{
	return m_RowCount;
}

SensorsTableModel::columnCount(const QModelIndex &parent) const
{
	return m_ColumnCount;
}

QVariant SensorsTableModel::data(const QModelIndex &index, int role) const
{
	int row = index.row();
	int col = index.column();

	qDebug() << QString("row %1, col%2, role %3")
				.arg(row).arg(col).arg(role);

	switch(role)
	{
	case Qt::DisplayRole:
	{

	}
		break;
	case Qt::FontRole:
	{

	}
		break;
	case Qt::BackgroundRole:
	{

	}
		break;
	case Qt::TextAlignmentRole:
	{
		return Qt::AlignRight + Qt::AlignVCenter;
	}
		break;
	case Qt::CheckStateRole:
	{
		if (row == 1 && col == 0) //add a checkbox to cell(1,0)
		{
			return Qt::Checked;
		}
	}
		break;
	}
	return QVariant();
}

QVariant SensorsTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal) {
			switch (section)
			{
			// TODO: THIS HAS TO BE DONE BETTER ! TEMPORARY
			case 0:
				return QString("Name");
			case 1:
				return QString("ID");
			case 2:
				return QString("Status");
			}
		}
	}
	return QVariant();
}
