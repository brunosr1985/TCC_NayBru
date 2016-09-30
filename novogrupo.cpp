#include "novogrupo.h"
#include "ui_novogrupo.h"

novoGrupo::novoGrupo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::novoGrupo)
{
    ui->setupUi(this);
}

novoGrupo::~novoGrupo()
{
    delete ui;
}
