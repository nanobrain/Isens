#ifndef ISENSE_H
#define ISENSE_H

#include <QMainWindow>
#include <QtGui>
#include <QMessageBox>
#include <QTableView>
#include <QDebug>
#include <QDialog>
#include <QPair>

#include "sensorstabledialog.h"
#include "sensorstablemodel.h"
#include "addsensordialog.h"

namespace Ui {
class ISense;
}

class ISense : public QMainWindow
{
    Q_OBJECT

public:
	explicit ISense(QWidget *parent = 0);
    ~ISense();

private:
    Ui::ISense *ui;
	SensorsTableDialog *m_sensorsTableDialog = 0;
	SensorsTableModel *m_sensorsTableModel = 0;
	AddSensorDialog *m_addSensorDialog = 0;

signals:
	void AddSensorToTable( QPair<QString, QString> pair);
public slots:
    void displayAbout();
	void createSensorsTable();
	void onSensorsTableDialogClosed();
	void createAddSensorDialog();
	void onAddSensorDialogClose(int Result);

};

#endif // ISENSE_H
