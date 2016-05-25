#ifndef SENSORSTABLEDIALOG_H
#define SENSORSTABLEDIALOG_H

#include <QDialog>

namespace Ui {
class SensorsTableDialog;
}

class SensorsTableDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SensorsTableDialog(QWidget *parent = 0);
    ~SensorsTableDialog();

private:
    Ui::SensorsTableDialog *ui;
};

#endif // SENSORSTABLEDIALOG_H
