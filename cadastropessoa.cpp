#include "cadastropessoa.h"
#include "ui_cadastropessoa.h"

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
