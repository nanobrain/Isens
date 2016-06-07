#include "isense.h"
#include "ui_isense.h"

ISense::ISense(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::ISense)
{
	//Create Sensors Table Dialog model
	m_sensorsTableModel = new SensorsTableModel(this); // TODO: MAKE IT SINGLETON
	connect(this,SIGNAL(AddSensorToTable(QPair<QString,QString>)),m_sensorsTableModel,SLOT(onAddSensorToTable(QPair<QString,QString>)));
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
void ISense::onSensorsTableDialogClosed()
{
	//Enable button
	ui->actionList_all_sensors->setEnabled(true);
	// Cleanup
	delete m_sensorsTableDialog;
	m_sensorsTableDialog=0;
}

void ISense::createSensorsTable()
{
	//Create Sensors Table Dialog window
	m_sensorsTableDialog = new SensorsTableDialog(this);
	//Disable button
	ui->actionList_all_sensors->setDisabled(true);
	// Assign model to table view
	m_sensorsTableDialog->setModel(m_sensorsTableModel);
	//Connect signal of window closing
	connect(m_sensorsTableDialog,SIGNAL(finished(int)),this,SLOT(onSensorsTableDialogClosed()));
	//Append child window to mdiArea
	ui->mdiArea->addSubWindow(m_sensorsTableDialog,Qt::Window);
	//Show window
	m_sensorsTableDialog->show();
}

void ISense::createAddSensorDialog()
{
	if(!m_addSensorDialog)
	{
		m_addSensorDialog = new AddSensorDialog();
		m_addSensorDialog->setModal(true);
		connect(m_addSensorDialog,SIGNAL(finished(int)),this,SLOT(onAddSensorDialogClose(int)));
		m_addSensorDialog->show();
	}
	else
		qDebug()<<"ERROR";
}

void ISense::onAddSensorDialogClose(int Result)
{
	if(Result == QDialog::Accepted)
	{
		qDebug() <<"User sets:"<<endl<<"Name: "<<m_addSensorDialog->GetOutput().first <<endl<<"IP: "<< m_addSensorDialog->GetOutput().second<<endl;
		emit AddSensorToTable ( m_addSensorDialog->GetOutput() );
	}

	delete m_addSensorDialog;
	m_addSensorDialog=0;
}
