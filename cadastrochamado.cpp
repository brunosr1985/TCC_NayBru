#include "cadastrochamado.h"
#include "ui_cadastrochamado.h"
#include "matrizraci.h"
#include "selecionadisp.h"



cadastrochamado::cadastrochamado(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cadastrochamado)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","conn");
    db.setHostName("tccnaybru.cgqgmlbbcd8e.us-west-2.rds.amazonaws.com");
    db.setDatabaseName("tccnaybru");
    db.setPassword("bu381025");
    db.setUserName("brunosr");
    db.setPort(5432);
    db.open();

    QSqlQuery *fillCombo = new QSqlQuery(db);
    QStringList lista;

    fillCombo->prepare("SELECT estado FROM status");
    fillCombo->exec();
    while(fillCombo->next())
    {
        lista.append(fillCombo->value(0).toString());
    }
    lista.clear();

    fillCombo->prepare("SELECT prioridade FROM prioridade");
    fillCombo->exec();
    while(fillCombo->next())
    {
        lista.append(fillCombo->value(0).toString());
    }

    ui->setupUi(this);
    ui->comboPrioridade->clear();
    ui->comboPrioridade->addItems(lista);
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


    QString aux_status;
    QSqlQuery *query = new QSqlQuery(db);
    QSqlQuery *query2 = new QSqlQuery(db);

    query2->prepare("SELECT id_status FROM status WHERE statusNome = ?");
    query2->addBindValue(ui->comboStatus->currentText());
    aux_status = query2->exec();

    query->prepare("INSERT INTO chamado (status,descricao) VALUES ?,?");
    query->addBindValue(aux_status);
    query->addBindValue(ui->descricaoChamado->toPlainText());
    query->exec();
}
