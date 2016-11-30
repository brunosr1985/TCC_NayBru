#include "cadastrodispositivo.h"
#include "ui_cadastrodispositivo.h"
#include "tipodisp.h"

cadastrodispositivo::cadastrodispositivo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cadastrodispositivo)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","conn");
    db.setHostName("localhost");/*db.setHostName("tccnaybru.cgqgmlbbcd8e.us-west-2.rds.amazonaws.com");*/
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
    db.close();

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
    tipoDisp *td = new tipoDisp(this);
    td->setAttribute(Qt::WA_DeleteOnClose);
    td->show();

}

void cadastrodispositivo::on_pushButton_2_clicked()
{
    QString auxS = NULL;
    int aux_status;
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","conn");
    QString aux1 = ui->lineNome->text();
    QString aux2 = ui->lineLocal->text();



    db.setHostName("localhost");/*db.setHostName("tccnaybru.cgqgmlbbcd8e.us-west-2.rds.amazonaws.com");*/
    db.setDatabaseName("tccnaybru");
    db.setPassword("bu381025");
    db.setUserName("brunosr");
    db.setPort(5432);
    db.open();
    QSqlQuery *query = new QSqlQuery(db);

    query->prepare("SELECT id_tipo FROM tipo_d WHERE tipo = ?");
    query->addBindValue(ui->comboTipo->currentText());
    query->exec();
    query->next();
    aux_status = query->value(0).toInt();

    //aux_status = query->value("id_tipo").toInt();

    query->prepare("INSERT INTO dispositivo (dispositivo,tipo,local) VALUES (?,?,?)");
    query->addBindValue(aux1);
    query->addBindValue(aux_status);
    query->addBindValue(aux2);


    if(query->exec())
       {
        QMessageBox messageBox;
        messageBox.information(0,"Sucesso!","Cadastro realizado com sucesso");
        messageBox.setFixedSize(500,200);
        query->exec("SELECT id_dispositivos FROM dispositivos");
        query->last();
        auxS = query->value(0).toString();
        ui->lineID->clear();
        ui->lineID->setText(auxS);
        db.close();
    }
    else
    {
        /*erro = query->lastError().text();
        QMessageBox messageBox;
        messageBox.critical(0,"Erro!",erro);
        messageBox.setFixedSize(500,200);*/

    }

}

void cadastrodispositivo::atualizadados()
{    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","conn");
     db.setHostName("localhost");/*db.setHostName("tccnaybru.cgqgmlbbcd8e.us-west-2.rds.amazonaws.com");*/
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
     db.close();
     ui->comboTipo->clear();
     ui->comboTipo->addItems(lista);
}


void cadastrodispositivo::on_botaoAtualizar_clicked()
{
    ui->comboTipo->clear();
    atualizadados();
}

void cadastrodispositivo::on_botaoNovo_clicked()
{
    ui->lineID->clear();
    ui->lineLocal->clear();
    ui->lineNome->clear();
    ui->comboTipo->setCurrentIndex(0);
}
