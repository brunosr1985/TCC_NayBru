#ifndef TIPODISP_H
#define TIPODISP_H

#include <QDialog>

namespace Ui {
class tipoDisp;
}

class tipoDisp : public QDialog
{
    Q_OBJECT

public:
    explicit tipoDisp(QWidget *parent = 0);
    ~tipoDisp();

private:
    Ui::tipoDisp *ui;
};

#endif // TIPODISP_H
