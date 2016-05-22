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
