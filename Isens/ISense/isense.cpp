#include "isense.h"
#include "ui_isense.h"

ISense::ISense(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::ISense)
{
	ui->setupUi(this);
}

ISense::~ISense()
{
	delete ui;
}

// Slots definitions
void ISense::displayAbout()
{
	QMessageBox::about(this, tr("About"),
		tr("Politechnika Wrocławska"));
}
void ISense::sensorsTableDialogClosed()
{
	//Enable button
	ui->actionList_all_sensors->setEnabled(true);
}

void ISense::createSensorsTable()
{
	//Create window
	sensorsTableDialog = new SensorsTableDialog();
	//Disable button
	ui->actionList_all_sensors->setDisabled(true);
	//Connect signal of window closing
	QObject::connect(sensorsTableDialog,SIGNAL(finished(int)),this,SLOT(sensorsTableDialogClosed()));
	//Append child window to mdiArea
	ui->mdiArea->addSubWindow(sensorsTableDialog,Qt::Window);
	//Show window
	sensorsTableDialog->show();
}
