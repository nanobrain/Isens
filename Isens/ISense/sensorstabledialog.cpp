#include "sensorstabledialog.h"
#include "ui_sensorstabledialog.h"

SensorsTableDialog::SensorsTableDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SensorsTableDialog)
{
    ui->setupUi(this);
}

SensorsTableDialog::~SensorsTableDialog()
{
    delete ui;
}
