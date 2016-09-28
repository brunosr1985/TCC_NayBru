#ifndef SELECIONADISP_H
#define SELECIONADISP_H

#include <QDialog>

namespace Ui {
class selecionadisp;
}

class selecionadisp : public QDialog
{
    Q_OBJECT

public:
    explicit selecionadisp(QWidget *parent = 0);
    ~selecionadisp();

private:
    Ui::selecionadisp *ui;
};

#endif // SELECIONADISP_H
