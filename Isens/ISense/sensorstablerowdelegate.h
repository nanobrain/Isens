#ifndef SENSORSTABLEROWDELEGATE_H
#define SENSORSTABLEROWDELEGATE_H

#include <QObject>
#include <QItemDelegate>
#include <QApplication>
#include <QSize>
#include <QModelIndex>
#include <QPainter>
#include <QString>
#include <QDebug>
#include <QVariant>
#include <QLabel>

// Delegate class
class SensorsTableRowDelegate : public QItemDelegate
{
	Q_OBJECT
public:
	SensorsTableRowDelegate(QObject *parent = 0)
			: QItemDelegate(parent){qDebug() << "Delegate created"<<endl;}

	// Reimplementation of methods inherited from base class
	QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;
	void setEditorData(QWidget *editor, const QModelIndex &index) const Q_DECL_OVERRIDE;
	void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const Q_DECL_OVERRIDE;
	void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const Q_DECL_OVERRIDE;
	/*/////////////////////////////////////////*/

	enum Columns
	{
		COL_NAME,
		COL_ID,
		COL_STATUS
	};

signals:
	// Carries information about row which was clicked
	void click(int);
public slots:
	// Invokes status update
	void update();
	void CommitDataAndCloseEditor();
};

#endif // SENSORSTABLEROWDELEGATE_H
