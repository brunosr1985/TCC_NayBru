#include "tipodisp.h"
#include "ui_tipodisp.h"

tipoDisp::tipoDisp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tipoDisp)
{
    ui->setupUi(this);
}

tipoDisp::~tipoDisp()
{
    delete ui;
}
