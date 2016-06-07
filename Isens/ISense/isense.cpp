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

void ISense::createAddSensorDialog()
{
	if(!addSensorDialog)
	{
		addSensorDialog = new AddSensorDialog();
		addSensorDialog->setModal(true);
		addSensorDialog->show();
		connect(addSensorDialog,SIGNAL(accepted()),this,SLOT(onAddSensorDialogAccepted()));
		connect(addSensorDialog,SIGNAL(AddSensorDialogClosing()),this,SLOT(onAddSensorDialogClose()));
	}
}

void ISense::onAddSensorDialogAccepted()
{
	if(addSensorDialog->isVisible())
	{
		qDebug() << addSensorDialog->GetOutput().first << addSensorDialog->GetOutput().second;
		emit AddSensorToTable ( addSensorDialog->GetOutput() );
	}
}

void ISense::onAddSensorDialogClose()
{
	delete addSensorDialog;
	addSensorDialog=0;
}
