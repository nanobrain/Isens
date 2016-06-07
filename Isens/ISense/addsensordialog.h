#ifndef ADDSENSORDIALOG_H
#define ADDSENSORDIALOG_H

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

	QPair<QString, QString> GetOutput();

private:
	Ui::AddSensorDialog *ui;
signals:
	void AddSensorDialogClosing();
public slots:
	void onClose();
};

#endif // ADDSENSORDIALOG_H
