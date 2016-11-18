#include "cadastrodispositivo.h"
#include "ui_cadastrodispositivo.h"
#include "tipodisp.h"

cadastrodispositivo::cadastrodispositivo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cadastrodispositivo)
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

    fillCombo->prepare("SELECT tipo FROM tipo_d");
    fillCombo->exec();
    while(fillCombo->next())
    {
        lista.append(fillCombo->value(0).toString());
    }

    ui->setupUi(this);
    ui->comboTipo->clear();
    ui->comboTipo->addItems(lista);
}

cadastrodispositivo::~cadastrodispositivo()
{
    delete ui;
}

void cadastrodispositivo::on_pushButton_3_clicked()
{
    this->close();
}

void cadastrodispositivo::on_pushButton_4_clicked()
{
    tipoDisp *td = new tipoDisp();
    td->show();
}

void cadastrodispositivo::on_pushButton_2_clicked()
{
    /*QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","conn");
    db.setHostName("tccnaybru.cgqgmlbbcd8e.us-west-2.rds.amazonaws.com");
    db.setDatabaseName("tccnaybru");
    db.setPassword("bu381025");
    db.setUserName("brunosr");
    db.setPort(5432);
    db.open();


    QString aux_status;
    QSqlQuery *query = new QSqlQuery(db);
    QSqlQuery *query2 = new QSqlQuery(db);

    query2->prepare("SELECT id_tipo FROM tipo_d WHERE tipo = ?");
    query2->addBindValue(ui->comboTipo->currentText());
    aux_status = query2->exec();

    query->prepare("INSERT INTO dispositivo (dispositivo,tipo,local) VALUES ?,?,?);
    query->addBindValue(aux_status);
    query->addBindValue(ui->descricaoChamado->toPlainText());
    query->exec();
    */
}
