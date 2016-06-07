#ifndef SENSORSTABLEDIALOG_H
#define SENSORSTABLEDIALOG_H

#include <QDialog>
#include "sensorstablemodel.h"

namespace Ui {
class SensorsTableDialog;
}

class SensorsTableDialog : public QDialog
{
	Q_OBJECT

public:
	explicit SensorsTableDialog(QWidget *parent = 0);
	void setModel(QAbstractTableModel* m_model);
	~SensorsTableDialog();

private:
	Ui::SensorsTableDialog *ui;
	SensorsTableModel *m_model;
};

#endif // SENSORSTABLEDIALOG_H
