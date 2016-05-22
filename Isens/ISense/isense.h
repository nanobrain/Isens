#ifndef ISENSE_H
#define ISENSE_H

#include <QMainWindow>

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
};

#endif // ISENSE_H
