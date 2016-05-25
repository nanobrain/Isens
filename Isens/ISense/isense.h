#ifndef ISENSE_H
#define ISENSE_H

#include <QMainWindow>
#include <QtGui>
#include <QMessageBox>
#include <QTableView>
#include "sensorstabledialog.h"

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
    SensorsTableDialog *sensorsTableDialog;

public slots:
    void displayAbout();
    void createSensorsTable();
    void sensorsTableDialogClosed();

};

#endif // ISENSE_H
