#include "selecionadisp.h"
#include "ui_selecionadisp.h"

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
