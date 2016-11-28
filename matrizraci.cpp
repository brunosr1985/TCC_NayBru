#include "matrizraci.h"
#include "ui_matrizraci.h"
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtDebug>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QCompleter>
#include <iostream>

matrizRACI::matrizRACI(QWidget *parent, int aux) :
    QWidget(parent),
    ui(new Ui::matrizRACI)

    {
        db = QSqlDatabase::addDatabase("QPSQL","conn");
        db.setHostName("localhost");/*db.setHostName("tccnaybru.cgqgmlbbcd8e.us-west-2.rds.amazonaws.com");*/
        db.setDatabaseName("tccnaybru");
        db.setPassword("bu381025");
        db.setUserName("brunosr");
        db.setPort(5432);
        db.open();

        QSqlQuery *fillCombo = new QSqlQuery(db);
        QStringList lista;

        fillCombo->prepare("SELECT nome FROM pessoas");
        fillCombo->exec();
        while(fillCombo->next())
        {
            lista.append(fillCombo->value(0).toString());
        }
        fillCombo->finish();
        ui->setupUi(this);
        ui->comboPessoa->clear();
        ui->comboPessoa->addItems(lista);
        ui->spinBox->setValue(aux);
        QString qry = "SELECT pessoas.nome,matriz.id_chamado,matriz.responsible,matriz.accountable,matriz.consult,matriz.inform FROM matriz INNER JOIN pessoas ON matriz.id_pessoa = pessoas.id_pessoa WHERE matriz.id_chamado = "+ui->spinBox->value();
        //QString qry = "SELECT * FROM matriz WHERE id_chamado = "+ui->linhaChamado->text();
        QSqlQueryModel *modelo = new QSqlQueryModel();
        modelo->setQuery(qry,db);
        ui->tableView->setModel(modelo);
        ui->tableView->show();
        //ui->linhaChamado->insert((QString)aux);
    }

matrizRACI::matrizRACI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::matrizRACI)

    {
        ui->setupUi(this);
        }

matrizRACI::~matrizRACI()
{
    db.close();
    delete ui;
}

void matrizRACI::on_raciCarregar_clicked()
{

}

void matrizRACI::on_incluirPessoa_clicked()
{
    QSqlQuery *query = new QSqlQuery(db);
    int aux_chamado = ui->spinBox->value();
    QString chamado = QString::number(aux_chamado);
    QString pessoa = 0;
    bool aux_responsible = ui->Responsible->isChecked();
    QString responsible = QString(aux_responsible ? "true" : "false");
    bool aux_accountable = ui->Accountable->isChecked();
    QString accountable = QString(aux_accountable ? "true" : "false");
    bool aux_consult = ui->Consulted->isChecked();
    QString consult = QString(aux_consult ? "true" : "false");
    bool aux_inform = ui->Informed->isChecked();
    QString inform = QString(aux_inform ? "true" : "false");
//    QTableWidgetItem *aux_pessoa = new QTableWidgetItem(pessoa);
//    QTableWidgetItem *aux_R = new QTableWidgetItem(responsible);
//    QTableWidgetItem *aux_A = new QTableWidgetItem(accountable);
//    QTableWidgetItem *aux_C = new QTableWidgetItem(consult);
//    QTableWidgetItem *aux_I = new QTableWidgetItem(inform);

    QString auxP = ui->comboPessoa->currentText();
    QString query_string = "SELECT id_pessoa FROM pessoas WHERE nome = '"
    + auxP + "'";
    query->exec(query_string);
    query->next();
    pessoa = query->value("id_pessoa").toString();
//    ui->tableWidget->setItem(ui->tableWidget->rowCount()+1,1,aux_pessoa);
//    ui->tableWidget->setItem(ui->tableWidget->rowCount()+1,2,aux_R);
//    ui->tableWidget->setItem(ui->tableWidget->rowCount()+1,3,aux_A);
//    ui->tableWidget->setItem(ui->tableWidget->rowCount()+1,4,aux_C);
//    ui->tableWidget->setItem(ui->tableWidget->rowCount()+1,5,aux_I);
//    ui->tableWidget->show();

    QString qry = "INSERT INTO matriz (id_pessoa,id_chamado,responsible,accountable,consult,inform) VALUES ("+pessoa+","+chamado+","+responsible+","+accountable+","+consult+","+inform+")";
    query->exec(qry);

    qry = "SELECT pessoas.nome,matriz.id_chamado,matriz.responsible,matriz.accountable,matriz.consult,matriz.inform FROM matriz INNER JOIN pessoas ON matriz.id_pessoa = pessoas.id_pessoa WHERE matriz.id_chamado = "+chamado;
    query->exec(qry);
    //QString qry = "SELECT * FROM matriz WHERE id_chamado = "+ui->linhaChamado->text();
    QSqlQueryModel *modelo = new QSqlQueryModel();
    modelo->setQuery(query->lastQuery(),db);
    ui->tableView->setModel(modelo);
    ui->tableView->show();
}
