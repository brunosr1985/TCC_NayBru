#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include <QDebug>
#include <iostream>

using namespace std;

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{



}

void Login::on_pushButton_2_clicked()
{

    this->accept();
}

void Login::on_botaoNaoLoga_clicked()
{
    this->close();
}

void Login::on_botaoLogar_clicked()
{

    QString erro;
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","conn");
    db.setHostName("localhost");/*db.setHostName("tccnaybru.cgqgmlbbcd8e.us-west-2.rds.amazonaws.com");*/
    db.setDatabaseName("tccnaybru");
    db.setPassword("bu381025");
    db.setUserName("brunosr");
    db.setPort(5432);
    db.open();

    QString usuario;
    QString senha;
    bool administracao = false;
    QSqlQuery *query = new QSqlQuery(db);
    QSqlQuery *query2 = new QSqlQuery(db);


    usuario = ui->nomeUsuario->text();
    senha = ui->senhaUsuario->text();

    query->exec("SELECT usuario,senha FROM login WHERE usuario = '"+usuario+"' AND senha = '"+senha+"'");
    query2->exec("SELECT administrativo FROM login WHERE usuario = '"+usuario+"' AND senha = '"+senha+"'");
    query2->next();
    administracao = query2->value("administrativo").toBool();


    if(query->next())
    {

        //db.removeDatabase("conn");
        if(administracao)
        {
            query2->exec("UPDATE permissoes SET situacao=true WHERE permissao = 'administrativo'");
        }
        else
        {
            query2->exec("UPDATE permissoes SET situacao=false WHERE permissao = 'administrativo'");
        }
        db.close();
        //delete &db;
        query->finish();
        query2->finish();
        JanelaPrincipal *w = new JanelaPrincipal;
        w->show();
        this->hide();
    }
    else
    {
        /*
        JanelaPrincipal *w = new JanelaPrincipal;
        w->show();*/
        db.close();
        //db.removeDatabase("conn");
        //delete &db;
        query->finish();
        query2->finish();
        QMessageBox messageBox;
        messageBox.critical(0,"Erro","Erro de usuário e/ou senha");
        messageBox.setFixedSize(500,200);
    }

}
