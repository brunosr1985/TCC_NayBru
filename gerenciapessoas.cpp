#include "gerenciapessoas.h"
#include "ui_gerenciapessoas.h"

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
