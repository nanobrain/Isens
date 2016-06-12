#ifndef ISENSE_H
#define ISENSE_H

//#include "commons.h"
#include "sensorstablemodel.h"
#include "sensorstabledialog.h"
#include "connectioncontroller.h"
#include <QMessageBox>
#include <QMainWindow>
#include <QtGui>
#include <QTableView>
#include <QDialog>

extern SensorsTableModel *m_sensorsTableModel;
extern ConnectionController *m_connectionController;

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
	Ui::ISense* ui;
	SensorsTableDialog* m_sensorsTableDialog = NULL;

signals:
	void AddSensorToTable( Sensor* );
public slots:
    void displayAbout();
	void createSensorsTable();
	void onSensorsTableDialogClosed();	

};

#endif // ISENSE_H
