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

private slots:
    void on_botaoCancelar_clicked();

    void on_botaoSalvar_clicked();

private:
    Ui::tipoDisp *ui;
};

#endif // TIPODISP_H
