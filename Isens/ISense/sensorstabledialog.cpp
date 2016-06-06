#include "sensorstabledialog.h"
#include "ui_sensorstabledialog.h"

SensorsTableDialog::SensorsTableDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::SensorsTableDialog)
{

	Model = new SensorsTableModel(parent);

	ui->setupUi(this);
	// Assign model to table view
	ui->tableView->setModel(Model);

	// Define look of table
	ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	// TODO: Set minimal size of table to prevent text cropping

}

SensorsTableDialog::~SensorsTableDialog()
{
	delete ui;
}
