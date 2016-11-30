#include "gerenciapessoas.h"
#include "ui_gerenciapessoas.h"


gerenciaPessoas::gerenciaPessoas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gerenciaPessoas)
{
    ui->setupUi(this);
    //Bloqueia e desbloqueia os devidos campos

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","conn");
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

    ui->comboGrupo->clear();
    ui->comboGrupo->addItems(lista);

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
    QString Nome;
    QString Telefone;
    QString Ramal;
    QString Email;
    QString Depto;
    QString Cargo;

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","conn");
    db.setHostName("localhost");/*db.setHostName("tccnaybru.cgqgmlbbcd8e.us-west-2.rds.amazonaws.com");*/
    db.setDatabaseName("tccnaybru");
    db.setPassword("bu381025");
    db.setUserName("brunosr");
    db.setPort(5432);
    db.open();

    QSqlQuery *query = new QSqlQuery(db);
    query->prepare("SELECT * FROM pessoas WHERE id_pessoa = ?");
    query->addBindValue(ui->lineID->text().toInt());
    query->exec();
    query->last();
    Nome = query->value("nome").toString();
    ui->lineNome->setText(Nome);
    ui->lineNome->update();
    Telefone = query->value("telefone").toString();
    ui->lineTelefone->setText(Telefone);
    ui->lineTelefone->update();
    Ramal = query->value("ramal").toString();
    ui->lineRamal->setText(Ramal);
    ui->lineRamal->update();
    Email = query->value("email").toString();
    ui->lineEmail->setText(Email);
    ui->lineEmail->update();
    Depto = query->value("depto").toString();
    ui->lineDepto->setText(Depto);
    ui->lineDepto->update();
    Cargo = query->value("cargo").toString();
    ui->lineCargo->setText(Cargo);
    ui->lineCargo->update();
    aux = query->value("grupo").toInt();
    query->prepare("SELECT grupo FROM grupo_p WHERE id_grupo = ?");
    query->addBindValue(aux);
    query->exec();
    query->last();
    ui->comboGrupo->setEnabled(true);
    ui->comboGrupo->setCurrentIndex(ui->comboGrupo->findText(query->value(0).toString()));
    ui->comboGrupo->update();
    ui->comboGrupo->setEnabled(false);


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
