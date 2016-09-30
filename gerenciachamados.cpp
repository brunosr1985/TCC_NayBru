#include "gerenciachamados.h"
#include "ui_gerenciachamados.h"
#include "cadastrochamado.h"

gerenciaChamados::gerenciaChamados(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gerenciaChamados)
{
    ui->setupUi(this);
}

gerenciaChamados::~gerenciaChamados()
{
    delete ui;
}

void gerenciaChamados::on_novoChamado_clicked()
{
    cadastrochamado *novoC = new cadastrochamado();
    novoC->show();
}
