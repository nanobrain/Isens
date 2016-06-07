#ifndef ISENSE_H
#define ISENSE_H

#include <QMainWindow>
#include <QtGui>
#include <QMessageBox>
#include <QTableView>
#include <QDialog>
#include "sensorstabledialog.h"
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
	SensorsTableDialog *sensorsTableDialog = 0;
	AddSensorDialog *addSensorDialog = 0;

signals:
	void AddSensorToTable( QPair<QString, QString> );
public slots:
    void displayAbout();
    void createSensorsTable();
    void sensorsTableDialogClosed();
	void createAddSensorDialog();
	void onAddSensorDialogClose();
	void onAddSensorDialogAccepted();

};

#endif // ISENSE_H
