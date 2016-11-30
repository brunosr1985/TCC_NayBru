#include "cadastrochamado.h"
#include "ui_cadastrochamado.h"
#include "matrizraci.h"
#include "selecionadisp.h"



cadastrochamado::cadastrochamado(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cadastrochamado)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","conn");
    db.setHostName("localhost");/*db.setHostName("tccnaybru.cgqgmlbbcd8e.us-west-2.rds.amazonaws.com");*/
    db.setDatabaseName("tccnaybru");
    db.setPassword("bu381025");
    db.setUserName("brunosr");
    db.setPort(5432);
    db.open();

    int aux;
    QSqlQuery *fillCombo = new QSqlQuery(db);
    QSqlQuery *query = new QSqlQuery(db);
    QStringList lista;

    ui->spinBox->clear();
    query->exec("SELECT id_chamado FROM chamado");
    query->last();
    aux = query->value("id_chamado").toInt();
    aux = aux + 1;
    ui->spinBox->setValue(aux);

    fillCombo->prepare("SELECT estado FROM status");
    fillCombo->exec();
    while(fillCombo->next())
    {
        lista.append(fillCombo->value(0).toString());
    }
    ui->comboStatus->clear();
    ui->comboStatus->addItems(lista);
    lista.clear();

    fillCombo->prepare("SELECT prioridade FROM prioridade");
    fillCombo->exec();
    while(fillCombo->next())
    {
        lista.append(fillCombo->value(0).toString());
    }

    ui->tempoAbertura->setDateTime(QDateTime::currentDateTime());
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
    matrizRACI *raci = new matrizRACI(NULL,ui->spinBox->value());
    raci->setAttribute(Qt::WA_DeleteOnClose);
    raci->show();

}

void cadastrochamado::on_abreDisp_clicked()
{
    selecionadisp *disp = new selecionadisp(NULL,ui->spinBox->value());
    disp->setAttribute(Qt::WA_DeleteOnClose);
    disp->show();

}

void cadastrochamado::on_pushButton_2_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","conn");
    db.setHostName("localhost");/*db.setHostName("tccnaybru.cgqgmlbbcd8e.us-west-2.rds.amazonaws.com");*/
    db.setDatabaseName("tccnaybru");
    db.setPassword("bu381025");
    db.setUserName("brunosr");
    db.setPort(5432);
    db.open();

    QString aberto = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString status;
    QString aux_status = ui->comboStatus->currentText();
    QString prioridade;
    QString aux_prioridade = ui->comboPrioridade->currentText();
    bool aux_reincidente = ui->checkReinc->isChecked();
    QString reincidente = QString(aux_reincidente ? "true" : "false");
    QString descricao = ui->descricaoChamado->toPlainText();
    QString sla = NULL;
    QString qry;

    QSqlQuery *query = new QSqlQuery(db);
    QSqlQuery *query2 = new QSqlQuery(db);

    qry = "SELECT id_estado FROM status WHERE estado = '"+aux_status+"'";
    query2->exec(qry);
    query2->last();
    status = query2->value("id_estado").toString();

    qry = "SELECT id_prioridade FROM prioridade WHERE prioridade = '"+aux_prioridade+"'";
    query2->exec(qry);
    query2->last();
    prioridade = query2->value("id_prioridade").toString();

    qry = "INSERT INTO chamado (id_chamado,status,prioridade, reincidente, descricao, aberto) VALUES (nextval('chamado_id_chamado_seq'::regclass),"+status+","+prioridade+","+reincidente+",'"+descricao+"',timestamp '"+aberto+"')";

    if(query->exec(qry))
       {
        QMessageBox messageBox;
        messageBox.information(0,"Sucesso!","Cadastro do chamado aberto com sucesso, favor cadastrar RACI e Ativos");
        messageBox.setFixedSize(500,200);
        qry = "SELECT id_chamado FROM chamado";
        query->exec(qry);
        query->last();
        ui->spinBox->setValue(query->value("id_chamado").toInt());
        ui->pushButton_2->setEnabled(false);

        db.close();
    }
    else
    {
        /*erro = query->lastError().text();
        QMessageBox messageBox;
        messageBox.critical(0,"Erro!",erro);
        messageBox.setFixedSize(500,200);*/

    }

    ui->abreDisp->setEnabled(true);
    ui->abreRACI->setEnabled(true);
}

void cadastrochamado::on_toolButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","conn");
    db.setHostName("localhost");/*db.setHostName("tccnaybru.cgqgmlbbcd8e.us-west-2.rds.amazonaws.com");*/
    db.setDatabaseName("tccnaybru");
    db.setPassword("bu381025");
    db.setUserName("brunosr");
    db.setPort(5432);
    db.open();

    QSqlQuery *query = new QSqlQuery(db);
    int aux = ui->spinBox->value();

    query->prepare("SELECT tipo_d.sla FROM tipo_d INNER JOIN dispositivo ON dispositivo.tipo = tipo_d.id_tipo INNER JOIN chamxativo ON chamxativo.id_ativo = dispositivo.id_dispositivo INNER JOIN chamado ON chamxativo.id_chamado = chamado.id_chamado WHERE id_chamado = ?");
    query->addBindValue(aux);
    query->exec();

    ui->lineSLA->setText(query->value(0).toString());
}
