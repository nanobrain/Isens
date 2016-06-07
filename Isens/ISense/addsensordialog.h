#ifndef ADDSENSORDIALOG_H
#define ADDSENSORDIALOG_H

#include <QDebug>
#include <QDialog>
#include <QPair>

namespace Ui {
class AddSensorDialog;
}

class AddSensorDialog : public QDialog
{
	Q_OBJECT

public:
	explicit AddSensorDialog(QWidget *parent = 0);
	~AddSensorDialog();
	void clearResults();
	QPair<QString, QString> GetOutput();

private:
	Ui::AddSensorDialog *ui;
	QPair<QString, QString>* m_Results;

public slots:
	void onEdit();
	void onRejected();
};

#endif // ADDSENSORDIALOG_H
