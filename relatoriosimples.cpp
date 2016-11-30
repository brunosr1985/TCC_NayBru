#include "relatoriosimples.h"
#include "ui_relatoriosimples.h"

relatoriosimples::relatoriosimples(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::relatoriosimples)
{

    db = QSqlDatabase::addDatabase("QPSQL","conn");
    db.setHostName("localhost");/*db.setHostName("tccnaybru.cgqgmlbbcd8e.us-west-2.rds.amazonaws.com");*/
    db.setDatabaseName("tccnaybru");
    db.setPassword("bu381025");
    db.setUserName("brunosr");
    db.setPort(5432);
    db.open();
    query = new QSqlQuery(db);

    QSqlQuery *fillCombo = new QSqlQuery(db);
    QStringList lista;

    fillCombo->prepare("SELECT tipo FROM tipo_d");
    fillCombo->exec();
    while(fillCombo->next())
    {
        lista.append(fillCombo->value(0).toString());
    }


    ui->setupUi(this);
    ui->comboTipo->clear();
    ui->comboTipo->addItems(lista);
    ui->dateAbertura->setDate(QDate::currentDate());
}

relatoriosimples::~relatoriosimples()
{
    db.close();
    delete ui;
}



void relatoriosimples::atualizadados(QString aux)
{
    modelo = new QSqlQueryModel();
    modelo->setQuery(aux,db);
    ui->tableResultados->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableResultados->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    ui->tableResultados->setModel(modelo);
    ui->tableResultados->show();
}

void relatoriosimples::on_botaoAtivos_clicked()
{
    QString qry = NULL;
    QString tipod = ui->comboTipo->currentText();

    qry = "SELECT tipo_d.tipo, dispositivo.dispositivo, dispositivo.local FROM tipo_d INNER JOIN dispositivo ON dispositivo.tipo = tipo_d.id_tipo WHERE tipo_d.tipo = '"+tipod+"'";
    atualizadados(qry);



}


void relatoriosimples::on_botaoPessoas_clicked()
{
    QString qry = NULL;
    QString nome = ui->lineNome->text();

    qry = "SELECT pessoas.nome,pessoas.id_pessoa,pessoas.telefone,pessoas.ramal,pessoas.email,pessoas.depto,pessoas.cargo,grupo_p.grupo FROM pessoas INNER JOIN grupo_p ON pessoas.grupo = grupo_p.id_grupo WHERE pessoas.nome LIKE '%"+nome+"%'";
    atualizadados(qry);
}

void relatoriosimples::on_botaoChamados_clicked()
{
    QString qry = NULL;
    QString aberto = ui->dateAbertura->date().toString("yyyy-MM-dd");

    qry = "SELECT dispositivo.dispositivo,dispositivo.local,prioridade.prioridade,chamado.id_chamado,chamado.descricao,chamado.fechado,chamado.aberto,chamado.reincidente,status.estado FROM chamado INNER JOIN chamxativo ON chamxativo.id_chamado = chamado.id_chamado INNER JOIN dispositivo ON chamxativo.id_ativo = dispositivo.id_dispositivo INNER JOIN prioridade ON chamado.prioridade = prioridade.id_prioridade INNER JOIN status ON chamado.status = status.id_estado WHERE chamado.aberto BETWEEN  '"+aberto+" 00:00:00' AND '"+aberto+" 23:59:59'";
    atualizadados(qry);
}
