#ifndef GERENCIADISPOSITIVO_H
#define GERENCIADISPOSITIVO_H

#include <QDialog>

namespace Ui {
class gerenciaDispositivo;
}

class gerenciaDispositivo : public QDialog
{
    Q_OBJECT

public:
    explicit gerenciaDispositivo(QWidget *parent = 0);
    ~gerenciaDispositivo();

private slots:
    void on_novoDIsp_clicked();

private:
    Ui::gerenciaDispositivo *ui;
};

#endif // GERENCIADISPOSITIVO_H
