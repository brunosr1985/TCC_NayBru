#include "cadastrostatus.h"
#include "ui_cadastrostatus.h"

cadastrostatus::cadastrostatus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastrostatus)
{
    ui->setupUi(this);
}

cadastrostatus::~cadastrostatus()
{
    delete ui;
}
