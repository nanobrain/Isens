#include "addsensordialog.h"
#include "ui_addsensordialog.h"

AddSensorDialog::AddSensorDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::AddSensorDialog)
{
	ui->setupUi(this);
}

AddSensorDialog::~AddSensorDialog()
{
	delete ui;
}


QPair<QString, QString> AddSensorDialog::GetOutput()
{
	QPair<QString, QString> out;
	QString name = ui->NameText->text();
	QString address = ui->IPText->text();

	if(!name.isEmpty() && !address.isEmpty()) // TODO: ADD BETTER INPUT CHECK.
	{
		out.first = name;
		out.second = address;
	}
	return out;
}

void AddSensorDialog::onClose()
{
	emit AddSensorDialogClosing();
}
