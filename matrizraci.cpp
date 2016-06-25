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
    QString erro;
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","conn");
    db.setHostName("localhost");
    db.setDatabaseName("TCC");
    db.setPassword("raciuser");
    db.setUserName("raci");
    db.setPort(5432);
    erro = db.open("raciuser","raci");

    modelo = new QSqlTableModel(this,db);

    modelo->setTable("matriz");
    modelo->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelo->select();
    ui->raciTabela->setModel(modelo);
    ui->raciTabela->show();

}
