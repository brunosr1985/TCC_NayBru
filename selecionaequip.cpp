#include "selecionaequip.h"
#include "ui_selecionaequip.h"

selecionadisp::selecionadisp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selecionadisp)
{
    ui->setupUi(this);
}

selecionadisp::~selecionadisp()
{
    delete ui;
}
