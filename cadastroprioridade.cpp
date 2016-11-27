#include "cadastroprioridade.h"
#include "ui_cadastroprioridade.h"

cadastroprioridade::cadastroprioridade(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastroprioridade)
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

cadastroprioridade::~cadastroprioridade()
{
    delete ui;
}

void cadastroprioridade::on_botaoAdicionar_clicked()
{
    query->prepare("INSERT INTO prioridade (prioridade) VALUES (?)");
    query->addBindValue(ui->linePrioridade->text());
    query->exec();
    atualizaDados();
}

void cadastroprioridade::on_botaoEditar_clicked()
{
    int aux;
    QString auxS = ui->tablePrioridade->model()->data(ui->tablePrioridade->currentIndex()).toString();
    QString aux2 = ui->linePrioridade->text();

    query->exec("SELECT id_prioridade FROM prioridade WHERE prioridade = '"+auxS+"'");
    query->next();
    aux = query->value("id_prioridade").toInt();

    query->prepare("UPDATE prioridade SET prioridade = ? WHERE id_prioridade = ? OR prioridade = ?");
    query->addBindValue(aux2);
    query->addBindValue(aux);
    query->addBindValue(auxS);
    query->exec();

   atualizaDados();
}

void cadastroprioridade::atualizaDados()
{
    modelo->setTable("view_prioridade");
    modelo->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelo->select();
    ui->tablePrioridade->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tablePrioridade->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    ui->tablePrioridade->setModel(modelo);
}
