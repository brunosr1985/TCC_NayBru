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

void tipoDisp::on_botaoCancelar_clicked()
{
    this->close();
}

void tipoDisp::on_botaoSalvar_clicked()
{
    /*QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","conn");
    db.setHostName("tccnaybru.cgqgmlbbcd8e.us-west-2.rds.amazonaws.com");
    db.setDatabaseName("tccnaybru");
    db.setPassword("bu381025");
    db.setUserName("brunosr");
    db.setPort(5432);
    db.open();

    QSqlQuery *query = new QSqlQuery(db);*/

}
