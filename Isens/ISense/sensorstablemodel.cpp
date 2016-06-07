#include "sensorstablemodel.h"
#include <typeinfo>

SensorsTableModel::SensorsTableModel(QObject *parent)
		:QAbstractTableModel(parent)
{
	qDebug()<<"Creating Sensors Table MODEL ! 1"<<endl;
}

SensorsTableModel::SensorsTableModel(QList< QPair<QString,QString> > pairs, QObject *parent):
	m_listOfPairs(pairs)
{
	Q_UNUSED(parent);
	qDebug()<<"Creating Sensors Table MODEL ! 2"<<endl;
}

SensorsTableModel::~SensorsTableModel()
{
	qDebug()<<"Deleting Sensors Table MODEL !"<<endl;
}

int SensorsTableModel::rowCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	return m_listOfPairs.size();
}

int SensorsTableModel::columnCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	return 2;
}

QVariant SensorsTableModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
			return QVariant();

	if (index.row() >= m_listOfPairs.size() || index.row() < 0)
			 return QVariant();

	/*qDebug() << QString("row %1, col%2, role %3")
				.arg(row).arg(col).arg(role);*/

	switch(role)
	{
	case Qt::DisplayRole:
	{
		QPair<QString, QString> pair = m_listOfPairs.at(index.row());
	if (index.column() == 0)
		return pair.first;
	else if (index.column() == 1)
		return pair.second;
	}
		break;
		/*
	case Qt::EditRole:
	{
		if(index.column() == COL_NAME)
		{

		}
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
		return Qt::AlignHCenter + Qt::AlignVCenter;
	}
		break;
	case Qt::CheckStateRole:
	{

	}
		break;
	default:
	{
		return QVariant();
	}
		break;
		*/
	}
	return QVariant();
}

bool SensorsTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if (index.isValid() && role == Qt::EditRole) {
		int row = index.row();

		QPair<QString, QString> p = m_listOfPairs.value(row);

			if (index.column() == 0)
				p.first = value.toString();
			else if (index.column() == 1)
				p.second = value.toString();
	else
		return false;

	m_listOfPairs.replace(row, p);
		emit(dataChanged(index, index));

	return true;
	}

		return false;
}

QVariant SensorsTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role != Qt::DisplayRole)
			 return QVariant();

	if (orientation == Qt::Horizontal) {
		switch (section)
		{
		// TODO: THIS HAS TO BE DONE BETTER ! TEMPORARY
		case 0:
			return tr("Name");
		case 1:
			return tr("IP");
		default:
			return QVariant();
		}
	}
	return QVariant();
}

void SensorsTableModel::addEntry(QPair<QString,QString> NewPair)
{
	QList< QPair<QString, QString> >list = getList();
	// TODO: LET USER CHANGE THE NAME IF IT ALREADY EXIST !
	if (!list.contains(NewPair)) {
		insertRows(0, 1, QModelIndex());
		setData(index(0, 0, QModelIndex()), NewPair.first, Qt::EditRole);
		setData(index(0, 1, QModelIndex()), NewPair.second, Qt::EditRole);
	} else {
		QMessageBox::information(0, tr("Duplicate Name"),tr("Sensor with this name and addres already exist"));
	}
}

bool SensorsTableModel::insertRows(int position, int rows, const QModelIndex &index)
 {
	 Q_UNUSED(index);
	 beginInsertRows(QModelIndex(), position, position+rows-1);

	 for (int row=0; row < rows; row++) {
		 QPair<QString, QString> pair(" ", " ");
		 m_listOfPairs.insert(position, pair);
	 }

	 endInsertRows();
	 return true;
 }

bool SensorsTableModel::removeRows(int position, int rows, const QModelIndex &index)
{
	Q_UNUSED(index);
	beginRemoveRows(QModelIndex(), position, position+rows-1);

	for (int row=0; row < rows; ++row) {
		m_listOfPairs.removeAt(position);
	}

	endRemoveRows();
	return true;
}

Qt::ItemFlags SensorsTableModel::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return Qt::ItemIsEnabled;

	return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
	// return Qt::ItemIsSelectable | Qt::ItemIsUserCheckable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;// | QAbstractTableModel::flags(index);
}

QList< QPair<QString, QString> > SensorsTableModel::getList()
{
	return m_listOfPairs;
}

void SensorsTableModel::onAddSensorToTable(QPair<QString,QString> pair)
{
	qDebug()<<"AddSensorToTable";
	addEntry(pair);
}
