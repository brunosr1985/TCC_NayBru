#include "matrizraci.h"
#include "ui_matrizraci.h"
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtDebug>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>

matrizRACI::matrizRACI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::matrizRACI)
{

    ui->setupUi(this);
}

matrizRACI::~matrizRACI()
{
    delete ui;
}

void matrizRACI::on_raciCarregar_clicked()
{
/*    QString erro;
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","conn");
    db.setHostName("localhost");
    db.setDatabaseName("postgres");
    db.setPassword("bu381025");
    db.setUserName("tccnaybru");
    db.setPort(5432);
    erro = db.open("postgres","bu381025");
*/
    QString erro;
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","conn");
    db.setHostName("tccnaybru.cgqgmlbbcd8e.us-west-2.rds.amazonaws.com");
    db.setDatabaseName("tccnaybru");
    db.setPassword("bu381025");
    db.setUserName("brunosr");
    db.setPort(5432);
    erro = db.open("brunosr","bu381025");
    db.close();

    db.close();


}
