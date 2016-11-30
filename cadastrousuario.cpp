#include "cadastrousuario.h"
#include "ui_cadastrousuario.h"

cadastrousuario::cadastrousuario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastrousuario)
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

cadastrousuario::~cadastrousuario()
{
    delete ui;
}

void cadastrousuario::on_botaoNovo_clicked()
{
    QSqlQuery *novoUsuario = new QSqlQuery(db);
    QString usuario;
    QString senha;
    bool aux;
    QString admin;

    usuario = ui->lineUsuario->text();
    senha = ui->lineSenha->text();
    aux = ui->checkAdmin->isChecked();

    if(aux)
    {
        admin = "true";
    }else
    {
        admin = "false";
    }


    novoUsuario->prepare("INSERT INTO login(usuario,senha,administrativo) VALUES ('"+usuario+"','"+senha+"',"+admin+")");
    novoUsuario->exec();
    //novoUsuario->finish();
    atualizadados();
}


void cadastrousuario::on_alteraSenha_clicked()
{
    QString usuario = ui->lineUsuario->text();
    QString senha = ui->lineSenha->text();
    query->exec("UPDATE login SET senha = '"+senha+"' WHERE usuario = '"+usuario+"'");
    //query->finish();
    atualizadados();
}

void cadastrousuario::atualizadados()
{
    modelo->setTable("usuarios");
    modelo->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelo->select();
    ui->tableUsuarios->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableUsuarios->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    ui->tableUsuarios->setModel(modelo);


 }

