#include "cadastropessoa.h"
#include "ui_cadastropessoa.h"
#include "novogrupo.h"

Cadastropessoa::Cadastropessoa(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cadastropessoa)
{
    ui->setupUi(this);
}

Cadastropessoa::~Cadastropessoa()
{
    delete ui;
}

void Cadastropessoa::on_Novo_Grupo_clicked()
{
    novoGrupo *ng = new novoGrupo();
    ng->setAttribute(Qt::WA_DeleteOnClose);
    ng->show();
}

void Cadastropessoa::on_Pessoa_Salvar_clicked()
{
    QString erro;
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","conn");
    db.setHostName("tccnaybru.cgqgmlbbcd8e.us-west-2.rds.amazonaws.com");
    db.setDatabaseName("tccnaybru");
    db.setPassword("bu381025");
    db.setUserName("brunosr");
    db.setPort(5432);
    db.open();

    //Cria a query SQL para adicionar a nova pessoa, deixando ID em branco e por enquanto atribuindo a um grupo padrão
    QSqlQuery *query = new QSqlQuery(db);
    query->prepare("INSERT INTO pessoas (nome, telefone, ramal, email, depto, cargo, grupo) VALUES (?, ?, ?, ? ,?, ?, ?)");
    query->addBindValue(ui->pessoaNome->text());
    query->addBindValue(ui->pessoaTelefone->text().toInt());
    query->addBindValue(ui->pessoaRamal->text().toInt());
    query->addBindValue(ui->pessoaEmail->text());
    query->addBindValue(ui->pessoaDepto->text());
    query->addBindValue(ui->pessoaCargo->text());
    query->addBindValue(1);
    //query->exec();


    if(query->exec())
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

    }

}
