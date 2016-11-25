#include "cadastrousuario.h"
#include "ui_cadastrousuario.h"

cadastrousuario::cadastrousuario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastrousuario)
{
    ui->setupUi(this);
}

cadastrousuario::~cadastrousuario()
{
    delete ui;
}
