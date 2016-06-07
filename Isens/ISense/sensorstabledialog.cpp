#include "sensorstabledialog.h"
#include "ui_sensorstabledialog.h"

SensorsTableDialog::SensorsTableDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::SensorsTableDialog)
{
	ui->setupUi(this);
	ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	// TODO: Set minimal size of table to prevent text cropping

}

void SensorsTableDialog::setModel(QAbstractTableModel *Model)
{
	ui->tableView->setModel(Model);
}

SensorsTableDialog::~SensorsTableDialog()
{
	delete ui;
}
