#include "sensorstablerowdelegate.h"

QWidget* SensorsTableRowDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	if(index.column() == COL_STATUS)
	{
		return QItemDelegate::createEditor(parent, option, index);
	}
	else
	{
		return QItemDelegate::createEditor(parent, option, index);
	}
}

void SensorsTableRowDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
	if(index.column() == COL_STATUS)
	{
		QItemDelegate::setEditorData(editor, index);
	}
	else
	{
		QItemDelegate::setEditorData(editor, index);
	}
}

void SensorsTableRowDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
	if(index.column() == COL_STATUS)
	{
		QItemDelegate::setModelData(editor, model, index);

	}
	else
	{
		QItemDelegate::setModelData(editor, model, index);
	}
}

void SensorsTableRowDelegate::paint(QPainter* painter, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	qDebug() << "Paint";
	// Common instructions

	QItemDelegate::paint(painter, option, index);

	if (option.state & QStyle::State_Selected)
				painter->fillRect(option.rect, option.palette.highlight());

	// Specific for column instructions
	if(index.column() == COL_STATUS)
	{
	}
}
// Slots definitions
void SensorsTableRowDelegate::update(){}
void SensorsTableRowDelegate::CommitDataAndCloseEditor()
{
	//emit commitData();
	//emit closeEditor();
}
