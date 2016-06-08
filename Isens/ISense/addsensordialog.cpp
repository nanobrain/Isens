#include "addsensordialog.h"
#include "ui_addsensordialog.h"
/* Test Pushup */
AddSensorDialog::AddSensorDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::AddSensorDialog)
{
	m_Results = new QPair<QString,QString>();
	ui->setupUi(this);
	// Input validation
	//ui->IPText->setInputMask("000.000.000.000");
	QRegExpValidator *v = new QRegExpValidator(this);
	QRegExp rx("((1{0,1}[0-9]{0,2}|2[0-4]{1,1}[0-9]{1,1}|25[0-5]{1,1})\\.){3,3}(1{0,1}[0-9]{0,2}|2[0-4]{1,1}[0-9]{1,1}|25[0-5]{1,1})");
	v->setRegExp(rx);
	ui->IPText->setValidator(v);
}

AddSensorDialog::~AddSensorDialog()
{
	delete m_Results;
	m_Results=0;
	delete ui;
}

void AddSensorDialog::clearResults()
{
	delete m_Results;
	m_Results=0;
}

QPair<QString, QString> AddSensorDialog::GetOutput()
{
	// TODO: ADD CHECK FOR THIS POINTER
	return *m_Results;
}

void AddSensorDialog::onEdit()
{
	// TODO: ADD CHECK FOR RECEIVED VALUES
	m_Results->first = ui->NameText->text();
	m_Results->second = ui->IPText->text();
}

void AddSensorDialog::onRejected()
{}
