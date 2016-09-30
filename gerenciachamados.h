#ifndef GERENCIACHAMADOS_H
#define GERENCIACHAMADOS_H

#include <QDialog>

namespace Ui {
class gerenciaChamados;
}

class gerenciaChamados : public QDialog
{
    Q_OBJECT

public:
    explicit gerenciaChamados(QWidget *parent = 0);
    ~gerenciaChamados();

private slots:
    void on_novoChamado_clicked();

private:
    Ui::gerenciaChamados *ui;
};

#endif // GERENCIACHAMADOS_H
