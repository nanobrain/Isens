#include "sensorstabledialog.h"
#include "ui_sensorstabledialog.h"

SensorsTableDialog::SensorsTableDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SensorsTableDialog)
{
    ui->setupUi(this);

    // Define default columns
    QStandardItemModel *sensorsTableModel = new QStandardItemModel(this);
    sensorsTableModel->setHorizontalHeaderLabels(QString("Name;ID;Status;Table;Plot").split(";"));
    ui->tableView->setModel(sensorsTableModel);

    // Define look of table
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // TODO: Set minimal size of table to prevent text cropping

}

SensorsTableDialog::~SensorsTableDialog()
{
    delete ui;
}
