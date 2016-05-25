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

void ISense::displayAbout()
{
    QMessageBox::about(this, tr("About"),
        tr("Politechnika Wrocławska"));
}
