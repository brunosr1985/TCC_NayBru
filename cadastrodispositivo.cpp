#include "cadastrodispositivo.h"
#include "ui_cadastrodispositivo.h"

cadastrodispositivo::cadastrodispositivo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cadastrodispositivo)
{
    ui->setupUi(this);
}

cadastrodispositivo::~cadastrodispositivo()
{
    delete ui;
}

void cadastrodispositivo::on_pushButton_3_clicked()
{
    this->close();
}
