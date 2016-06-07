#include "addsensordialog.h"
#include "ui_addsensordialog.h"

AddSensorDialog::AddSensorDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::AddSensorDialog)
{
	m_Results = new QPair<QString,QString>("","");
	ui->setupUi(this);
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
