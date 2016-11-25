#include "cadastroprioridade.h"
#include "ui_cadastroprioridade.h"

cadastroprioridade::cadastroprioridade(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastroprioridade)
{
    ui->setupUi(this);
}

cadastroprioridade::~cadastroprioridade()
{
    delete ui;
}
