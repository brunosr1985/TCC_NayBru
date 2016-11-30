#include "gerenciachamados.h"
#include "ui_gerenciachamados.h"
#include "cadastrochamado.h"

gerenciaChamados::gerenciaChamados(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gerenciaChamados)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QPSQL","conn");
    db.setHostName("localhost");/*db.setHostName("tccnaybru.cgqgmlbbcd8e.us-west-2.rds.amazonaws.com");*/
    db.setDatabaseName("tccnaybru");
    db.setPassword("bu381025");
    db.setUserName("brunosr");
    db.setPort(5432);
    db.open();
    query = new QSqlQuery(db);

    modelo = new QSqlTableModel(parent,db);
    atualizadados();
}

gerenciaChamados::~gerenciaChamados()
{
    db.close();
    delete ui;
}


void gerenciaChamados::on_adicionaAcompanhamento_clicked()
{
    QString chamado = ui->lineID->text();
    QString acompanha = ui->lineAcompanhamento->text();
    QString qry;

    qry = "INSERT INTO acompanhamentos(id_chamado,acompanhamento) VALUES ("+chamado+",'"+acompanha+"')";
    query->prepare(qry);

    if(query->exec())
       {
        QMessageBox messageBox;
        messageBox.information(0,"Sucesso!","Acompanhamento adicionado com sucesso");
        messageBox.setFixedSize(500,200);
        atualizadados();
        db.close();
    }
    else
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Erro!","Erro ao adicionar acompanhamento!");
        messageBox.setFixedSize(500,200);
    }
}

void gerenciaChamados::atualizadados()
{

    QString chamado = ui->lineID->text();

    QString qry = "SELECT id_chamado, acompanhamento FROM acompanhamentos WHERE id_chamado = '"+chamado+"'";
    QSqlQueryModel *modelo = new QSqlQueryModel();
    modelo->setQuery(qry,db);
    ui->tableAcompanha->setModel(modelo);
    ui->tableAcompanha->show();

}



void gerenciaChamados::on_toolButton_clicked()
{
    QString id = ui->lineID->text();
    QString sla;
    QString status;
    bool reincidente;
    QDateTime aberto;
    QDateTime fechado;
    QString descricao;
    QString qry;

    query->prepare("SELECT tipo_d.sla FROM dispositivo INNER JOIN chamxativo ON chamxativo.id_ativo = dispositivo.id_dispositivo INNER JOIN tipo_d ON dispositivo.tipo = tipo_d.id_tipo WHERE chamxativo.id_chamado = "+id);
    query->exec();
    query->last();
    sla = query->value("sla").toString();

    query->prepare("SELECT * FROM chamado WHERE id_chamado = "+id);
    if(query->exec())
       {
        query->last();
        //sla = query->value("sla").toString();
        ui->lineSLA->setText(sla);
        status = query->value("status").toString();
        ui->comboStatus->setCurrentText(status);
        reincidente = query->value("reincidente").toBool();
        ui->checkReincidente->setEnabled(reincidente);
        aberto = query->value("aberto").toDateTime();
        ui->timeAberto->setDateTime(aberto);
        descricao = query->value("descricao").toString();
        ui->textDescricao->setPlainText(descricao);
        atualizadados();
        QMessageBox messageBox;
        messageBox.information(0,"Sucesso!","Chamado recuperado com sucesso");
        messageBox.setFixedSize(500,200);
        ui->abreDisp->setEnabled(true);
        ui->abreRACI->setEnabled(true);
    }
    else
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Erro!","Erro ao adicionar acompanhamento!");
        messageBox.setFixedSize(500,200);
    }

}

void gerenciaChamados::on_abreRACI_clicked()
{
    int id = ui->lineID->text().toInt();

    matrizRACI *raci = new matrizRACI(NULL,id);
    raci->setAttribute(Qt::WA_DeleteOnClose);
    raci->show();
}

void gerenciaChamados::on_abreDisp_clicked()
{
    int id = ui->lineID->text().toInt();

    selecionadisp *disp = new selecionadisp(NULL,id);
    disp->setAttribute(Qt::WA_DeleteOnClose);
    disp->show();
}
