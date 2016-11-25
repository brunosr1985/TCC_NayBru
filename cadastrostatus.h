#ifndef CADASTROSTATUS_H
#define CADASTROSTATUS_H

#include <QDialog>

namespace Ui {
class cadastrostatus;
}

class cadastrostatus : public QDialog
{
    Q_OBJECT

public:
    explicit cadastrostatus(QWidget *parent = 0);
    ~cadastrostatus();

private:
    Ui::cadastrostatus *ui;
};

#endif // CADASTROSTATUS_H
