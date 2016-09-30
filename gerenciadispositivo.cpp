#include "gerenciadispositivo.h"
#include "ui_gerenciadispositivo.h"
#include "cadastrodispositivo.h"

gerenciaDispositivo::gerenciaDispositivo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gerenciaDispositivo)
{
    ui->setupUi(this);
}

gerenciaDispositivo::~gerenciaDispositivo()
{
    delete ui;
}

void gerenciaDispositivo::on_novoDIsp_clicked()
{
    cadastrodispositivo *novoD = new cadastrodispositivo();
    novoD->show();
}
