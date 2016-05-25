#ifndef ISENSE_H
#define ISENSE_H

#include <QMainWindow>
#include <QtGui>
#include <QMessageBox>

namespace Ui {
class ISense;
}

class ISense : public QMainWindow
{
    Q_OBJECT

public:
    explicit ISense(QWidget *parent = 0);
    ~ISense();

private:
    Ui::ISense *ui;

public slots:
    void displayAbout();

};

#endif // ISENSE_H
