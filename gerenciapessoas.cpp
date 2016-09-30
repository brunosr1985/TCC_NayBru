#include "gerenciapessoas.h"
#include "ui_gerenciapessoas.h"
#include "cadastropessoa.h"

gerenciaPessoas::gerenciaPessoas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gerenciaPessoas)
{
    ui->setupUi(this);
}

gerenciaPessoas::~gerenciaPessoas()
{
    delete ui;
}

void gerenciaPessoas::on_novaPessoa_clicked()
{
    Cadastropessoa *cp = new Cadastropessoa();
    cp->show();
}
