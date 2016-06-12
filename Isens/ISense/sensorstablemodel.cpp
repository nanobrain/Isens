#include "sensorstablemodel.h"

SensorsTableModel::SensorsTableModel(QObject *parent)
		:QAbstractTableModel(parent)
{
	qDebug()<<"Creating Sensors Table MODEL ! 1"<<endl;
}

SensorsTableModel::SensorsTableModel(QObject *parent, QVector<Sensor*> vecSen):
	m_SensorList(vecSen)
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
	return m_SensorList.size();
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

	if (index.row() >= m_SensorList.size() || index.row() < 0)
			 return QVariant();

	/*qDebug() << QString("row %1, col%2, role %3")
				.arg(row).arg(col).arg(role);*/

	switch(role)
	{
	case Qt::DisplayRole:
	{
		Sensor* sen = m_SensorList.at(index.row());
	if (index.column() == COL_NAME)
		return sen->name();
	else if (index.column() == COL_IP)
		return sen->ID();
	}
		break;
		/*
	case Qt::EditRole:
	{
		if(index.column() == COL_NAME)
		{

		}
		else if(index.column() == COL_IP)
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

		Sensor* sen = m_SensorList.value(row);

			if (index.column() == COL_NAME)
				sen->name() = value.toString();
			else if (index.column() == COL_IP)
				sen->ID() = value.toString();
	else
		return false;

	m_SensorList.replace(row, sen);
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

void SensorsTableModel::addEntry(Sensor* sen)
{
	if (!getList().contains(sen)) {
		insertRows(0, 1, QModelIndex());
		setData(index(0, COL_NAME, QModelIndex()), sen->name(), Qt::EditRole);
		setData(index(0, COL_IP, QModelIndex()), sen->ID(), Qt::EditRole);
	} else {
		// TODO: LET USER CHANGE THE NAME IF IT ALREADY EXIST !
		QMessageBox::information(0, tr("Duplicate Name"),tr("Sensor with this name and address already exist"));
	}
}

void SensorsTableModel::addEntries(QVector<Sensor*> vSensors)
{
	foreach(Sensor* sen,vSensors)
		addEntry(sen);
}

bool SensorsTableModel::insertRows(int position, int rows, const QModelIndex &index)
 {
	 Q_UNUSED(index);
	 beginInsertRows(QModelIndex(), position, position+rows-1);

	 for (int row=0; row < rows; row++) {
		 Sensor* sen;
		 m_SensorList.insert(position, sen);
	 }

	 endInsertRows();
	 return true;
 }

bool SensorsTableModel::removeRows(int position, int rows, const QModelIndex &index)
{
	Q_UNUSED(index);
	beginRemoveRows(QModelIndex(), position, position+rows-1);

	for (int row=0; row < rows; ++row) {
		m_SensorList.removeAt(position);
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

QVector<Sensor*> SensorsTableModel::getList()
{
	return m_SensorList;
}

void SensorsTableModel::onAddSensorToTable(Sensor* sen)
{
	qDebug()<<"AddSensorToTable";
	addEntry(sen);
}

void SensorsTableModel::onAddSensorsToTable(QVector<Sensor*> vSen)
{
	qDebug()<<"AddSensorsToTable";
	addEntries(vSen);
}

void SensorsTableModel::onUpdateSensorList()
{
	/**/
}
