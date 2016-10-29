#include "cadastrochamado.h"
#include "ui_cadastrochamado.h"
#include "matrizraci.h"
#include "selecionadisp.h"



cadastrochamado::cadastrochamado(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cadastrochamado)
{
    ui->setupUi(this);
}

cadastrochamado::~cadastrochamado()
{
    delete ui;
}

void cadastrochamado::on_pushButton_3_clicked()
{

}

void cadastrochamado::on_abreRACI_clicked()
{
    matrizRACI *raci = new matrizRACI();
    raci->show();

}

void cadastrochamado::on_abreDisp_clicked()
{
    selecionadisp *disp = new selecionadisp();
    disp->show();

}

void cadastrochamado::on_pushButton_2_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","conn");
    db.setHostName("tccnaybru.cgqgmlbbcd8e.us-west-2.rds.amazonaws.com");
    db.setDatabaseName("tccnaybru");
    db.setPassword("bu381025");
    db.setUserName("brunosr");
    db.setPort(5432);
    db.open();

}
