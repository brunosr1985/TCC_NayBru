#include "login.h"
#include "ui_login.h"

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
    db.setHostName("tccnaybru.cgqgmlbbcd8e.us-west-2.rds.amazonaws.com");
    db.setDatabaseName("tccnaybru");
    db.setPassword("bu381025");
    db.setUserName("brunosr");
    db.setPort(5432);
    db.open();


    QString usuario;
    QString senha;
    QSqlQuery *query = new QSqlQuery(db);


    usuario = ui->nomeUsuario->text();
    senha = ui->senhaUsuario->text();


    query->prepare("SELECT usuario,senha FROM login WHERE usuario = ? AND  senha = ?");
    query->addBindValue(usuario);
    query->addBindValue(senha);
    query->exec();

    if(query->next())
    {
        db.close();
        //db.removeDatabase("conn");
        delete &db;
        delete &query;
        this->accept();
    }
    else
    {
        db.close();
        //db.removeDatabase("conn");
        delete &db;
        delete &query;
        QMessageBox messageBox;
        messageBox.critical(0,"Erro","Erro de usuário e/ou senha");
        messageBox.setFixedSize(500,200);
    }

}
