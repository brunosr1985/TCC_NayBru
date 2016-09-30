#include "cadastropessoa.h"
#include "ui_cadastropessoa.h"
#include "novogrupo.h"

Cadastropessoa::Cadastropessoa(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cadastropessoa)
{
    ui->setupUi(this);
}

Cadastropessoa::~Cadastropessoa()
{
    delete ui;
}

void Cadastropessoa::on_Novo_Grupo_clicked()
{
    novoGrupo *ng = new novoGrupo();
    ng->show();
}
