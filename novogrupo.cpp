#include "novogrupo.h"
#include "ui_novogrupo.h"
#include <QSqlRecord>
#include <QDebug>
#include <QSqlError>

novoGrupo::novoGrupo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::novoGrupo)
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
    atualizaDados();


}

novoGrupo::~novoGrupo()
{
    db.close();
    delete query;
    delete ui;
}

void novoGrupo::on_pushButton_2_clicked()
{
    this->close();
}

void novoGrupo::on_Adicionar_clicked()
{


    query->prepare("INSERT INTO grupo_p (grupo) VALUES (?)");
    query->addBindValue(ui->lineEdit->text());
    query->exec();
    atualizaDados();


    /*if(query->exec())
       {
        QMessageBox messageBox;
        messageBox.critical(0,"Sucesso!","Cadastro realizado com sucesso");
        messageBox.setFixedSize(500,200);
        db.close();
    }
    else
    {
        erro = query->lastError().text();
        QMessageBox messageBox;
        messageBox.critical(0,"Erro!",erro);
        messageBox.setFixedSize(500,200);

    }*/
}

void novoGrupo::on_botaoEditar_clicked()
{
    int aux;
    QString auxS = ui->tableView->model()->data(ui->tableView->currentIndex()).toString();
    QString query_string = "SELECT id_grupo FROM grupo_p WHERE grupo = '"
    + auxS + "'";

    /*query->prepare("SELECT id_grupo FROM grupo_p WHERE grupo = ':grupo'");
    query->bindValue(":grupo",auxS);*/

    query->exec(query_string);
    query->next();
    aux = query->value("id_grupo").toInt();

    query->prepare("UPDATE grupo_p SET grupo = ? WHERE id_grupo = ?");
    query->addBindValue(ui->lineEdit->text());
    query->addBindValue(aux);
    query->exec();
    atualizaDados();

}

void novoGrupo::on_botaoAtualizar_clicked()
{

}

void novoGrupo::atualizaDados()
{
    modelo->setTable("grupo_p_view");
    modelo->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelo->select();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    ui->tableView->setModel(modelo);
}

void novoGrupo::on_botaoInativo_clicked()
{

}
