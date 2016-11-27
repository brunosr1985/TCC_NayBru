#include "gerenciapessoas.h"
#include "ui_gerenciapessoas.h"


gerenciaPessoas::gerenciaPessoas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gerenciaPessoas)
{
    ui->setupUi(this);
    //Bloqueia e desbloqueia os devidos campos
    ui->lineID->setReadOnly(false);
    ui->lineCargo->setReadOnly(true);
    ui->lineDepto->setReadOnly(true);
    ui->lineEmail->setReadOnly(true);
    ui->lineRamal->setReadOnly(true);
    ui->lineTelefone->setReadOnly(true);
    ui->lineNome->setReadOnly(true);
    ui->comboGrupo->setEnabled(false);
}

gerenciaPessoas::~gerenciaPessoas()
{
    delete ui;
}

void gerenciaPessoas::on_Pessoa_Editar_clicked()
{
    //Bloqueia e desbloqueia os devidos campos
    ui->lineID->setReadOnly(true);
    ui->lineCargo->setReadOnly(false);
    ui->lineDepto->setReadOnly(false);
    ui->lineEmail->setReadOnly(false);
    ui->lineRamal->setReadOnly(false);
    ui->lineTelefone->setReadOnly(false);
    ui->lineNome->setReadOnly(false);
    ui->comboGrupo->setEnabled(true);
    ui->Pessoa_Salvar->setEnabled(true);
}

void gerenciaPessoas::on_Pessoa_Salvar_clicked()
{
    int aux;

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","conn");
    db.setHostName("localhost");/*db.setHostName("tccnaybru.cgqgmlbbcd8e.us-west-2.rds.amazonaws.com");*/
    db.setDatabaseName("tccnaybru");
    db.setPassword("bu381025");
    db.setUserName("brunosr");
    db.setPort(5432);
    db.open();

    QSqlQuery *query = new QSqlQuery(db);

    query->prepare("SELECT id_grupo FROM grupo_p WHERE grupo = ?");
    query->addBindValue(ui->comboGrupo->currentText());
    query->exec();
    query->next();
    aux = query->value(0).toInt();

    query->prepare("UPDATE pessoas SET nome = ?, telefone = ?, ramal = ?, email = ?, depto = ?, cargo = ?, grupo = ? WHERE id_pessoa = ?");
    query->addBindValue(ui->lineNome->text());
    query->addBindValue(ui->lineTelefone->text().toInt());
    query->addBindValue(ui->lineRamal->text().toInt());
    query->addBindValue(ui->lineEmail->text());
    query->addBindValue(ui->lineDepto->text());
    query->addBindValue(ui->lineCargo->text());
    query->addBindValue(aux);
    query->addBindValue(ui->lineID->text().toInt());
    query->exec();

    //Bloqueia e desbloqueia os devidos campos
    ui->lineID->setReadOnly(false);
    ui->lineCargo->setReadOnly(true);
    ui->lineDepto->setReadOnly(true);
    ui->lineEmail->setReadOnly(true);
    ui->lineRamal->setReadOnly(true);
    ui->lineTelefone->setReadOnly(true);
    ui->lineNome->setReadOnly(true);
    ui->comboGrupo->setEnabled(false);
}

void gerenciaPessoas::on_toolButton_clicked()
{
    int aux;

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","conn");
    db.setHostName("localhost");/*db.setHostName("tccnaybru.cgqgmlbbcd8e.us-west-2.rds.amazonaws.com");*/
    db.setDatabaseName("tccnaybru");
    db.setPassword("bu381025");
    db.setUserName("brunosr");
    db.setPort(5432);
    db.open();

    QSqlQuery *query = new QSqlQuery(db);
    query->prepare("SELECT nome FROM pessoas WHERE id_pessoa = ?");
    query->addBindValue(ui->lineID->text().toInt());
    query->exec();
    query->next();
    ui->lineNome->setText(query->value(0).toString());
    ui->lineNome->update();

    query->prepare("SELECT telefone FROM pessoas WHERE id_pessoa = ?");
    query->addBindValue(ui->lineTelefone->text());
    query->exec();
    query->next();
    ui->lineTelefone->setText(query->value(0).toString());
    ui->lineTelefone->update();

    query->prepare("SELECT ramal FROM pessoas WHERE id_pessoa = ?");
    query->addBindValue(ui->lineRamal->text());
    query->exec();
    query->next();
    ui->lineRamal->setText(query->value(0).toString());
    ui->lineRamal->update();

    query->prepare("SELECT email FROM pessoas WHERE id_pessoa = ?");
    query->addBindValue(ui->lineEmail->text());
    query->exec();
    query->next();
    ui->lineEmail->setText(query->value(0).toString());
    ui->lineEmail->update();

    query->prepare("SELECT depto FROM pessoas WHERE id_pessoa = ?");
    query->addBindValue(ui->lineDepto->text());
    query->exec();
    query->next();
    ui->lineDepto->setText(query->value(0).toString());
    ui->lineDepto->update();

    query->prepare("SELECT cargo FROM pessoas WHERE id_pessoa = ?");
    query->addBindValue(ui->lineCargo->text());
    query->exec();
    query->next();
    ui->lineCargo->setText(query->value(0).toString());
    ui->lineCargo->update();

    query->prepare("SELECT grupo FROM pessoas WHERE id_pessoas = ?");
    query->addBindValue(ui->lineID->text().toInt());
    query->exec();
    query->next();
    aux = query->value(0).toInt();
    query->prepare("SELECT grupo FROM grupo_p WHERE id_grupo = ?");
    query->addBindValue(aux);
    query->exec();
    query->next();
    ui->comboGrupo->setCurrentIndex(ui->comboGrupo->findText(query->value(0).toString()));
    ui->comboGrupo->update();

    //Bloqueia e desbloqueia os devidos campos
    ui->lineID->setReadOnly(false);
    ui->lineCargo->setReadOnly(true);
    ui->lineDepto->setReadOnly(true);
    ui->lineEmail->setReadOnly(true);
    ui->lineRamal->setReadOnly(true);
    ui->lineTelefone->setReadOnly(true);
    ui->lineNome->setReadOnly(true);
    ui->comboGrupo->setEnabled(false);
    ui->comboGrupo->setEnabled(false);
}
