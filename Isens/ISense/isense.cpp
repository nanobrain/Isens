#include "isense.h"
#include "ui_isense.h"

extern SensorsTableModel* m_sensorsTableModel;

ISense::ISense(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::ISense)
{
	qDebug()<<"Created ISense"<<endl;
	//Create Sensors Table Dialog model
	Sensor* sen= new Sensor(this,"Name","999");
	QVector<Sensor*> vSens;
	vSens.push_back(sen);
	m_sensorsTableModel = new SensorsTableModel(this,vSens); // TODO: MAKE IT SINGLETON
	ui->setupUi(this);
}

ISense::~ISense()
{
	delete ui;
}


// TODO: ALL THOSE METHODS AND FUNCTIONALLITIES SHOULD BE MOVED TO CONTROLLER CLASS
// THIS CLASS IS JUST FOR MAIN WINDOW, NOT FOR APP FUNCTIONALLITY
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
