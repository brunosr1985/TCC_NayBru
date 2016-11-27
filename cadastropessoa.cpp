#include "cadastropessoa.h"
#include "ui_cadastropessoa.h"
#include "novogrupo.h"

Cadastropessoa::Cadastropessoa(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cadastropessoa)
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

    fillCombo->prepare("SELECT grupo FROM grupo_p");
    fillCombo->exec();
    while(fillCombo->next())
    {
        lista.append(fillCombo->value(0).toString());
    }
    db.close();

    ui->setupUi(this);
    ui->pessoaGrupo->clear();
    ui->pessoaGrupo->addItems(lista);
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
    db = QSqlDatabase::addDatabase("QPSQL","conn");
    db.setHostName("localhost");/*db.setHostName("tccnaybru.cgqgmlbbcd8e.us-west-2.rds.amazonaws.com");*/
    db.setDatabaseName("tccnaybru");
    db.setPassword("bu381025");
    db.setUserName("brunosr");
    db.setPort(5432);
    db.open();
    QSqlQuery *query = new QSqlQuery(db);

    int aux;
    QString auxS = ui->pessoaGrupo->currentText();
    QString query_string = "SELECT id_grupo FROM grupo_p WHERE grupo = '"
    + auxS + "'";
    query->exec(query_string);
    query->next();
    aux = query->value("id_grupo").toInt();

    //Cria a query SQL para adicionar a nova pessoa, deixando ID em branco e por enquanto atribuindo a um grupo padrão

    query->prepare("INSERT INTO pessoas (nome, telefone, ramal, email, depto, cargo, grupo) VALUES (?, ?, ?, ? ,?, ?, ?)");
    query->addBindValue(ui->pessoaNome->text());
    query->addBindValue(ui->pessoaTelefone->text().toInt());
    query->addBindValue(ui->pessoaRamal->text().toInt());
    query->addBindValue(ui->pessoaEmail->text());
    query->addBindValue(ui->pessoaDepto->text());
    query->addBindValue(ui->pessoaCargo->text());
    query->addBindValue(aux);
    //query->exec();


    if(query->exec())
       {
        QMessageBox messageBox;

        /*query->prepare("SELECT id_pessoa FROM pessoas WHERE nome = ?,telefone = ?,ramal = ?,email = ?, depto = ?, cargo = ?");
        query->addBindValue(ui->pessoaNome->text());
        query->addBindValue(ui->pessoaTelefone->text().toInt());
        query->addBindValue(ui->pessoaRamal->text().toInt());
        query->addBindValue(ui->pessoaEmail->text());
        query->addBindValue(ui->pessoaDepto->text());
        query->addBindValue(ui->pessoaCargo->text());*/
        query->exec("SELECT id_pessoa FROM pessoas");
        query->last();
        auxS = query->value(0).toString();
        ui->pessoaID->clear();
        ui->pessoaID->insert(auxS);

        messageBox.information(0,"Sucesso!","Cadastro realizado com sucesso");
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

void Cadastropessoa::on_pushButton_clicked()
{
    ui->pessoaID->clear();
    ui->pessoaNome->clear();
    ui->pessoaTelefone->clear();
    ui->pessoaRamal->clear();
    ui->pessoaEmail->clear();
    ui->pessoaDepto->clear();
    ui->pessoaCargo->clear();
    ui->pessoaGrupo->setCurrentIndex(0);
}

void Cadastropessoa::on_toolButton_clicked()
{
    QSqlQuery *fillCombo = new QSqlQuery(db);
    QStringList lista;

    fillCombo->prepare("SELECT grupo FROM grupo_p");
    fillCombo->exec();
    while(fillCombo->next())
    {
        lista.append(fillCombo->value(0).toString());
    }
    db.close();

    ui->pessoaGrupo->clear();
    ui->pessoaGrupo->addItems(lista);
}
