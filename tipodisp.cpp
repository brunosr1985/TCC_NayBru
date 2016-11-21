#include "tipodisp.h"
#include "ui_tipodisp.h"

tipoDisp::tipoDisp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tipoDisp)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QPSQL","conn");
    db.setHostName("tccnaybru.cgqgmlbbcd8e.us-west-2.rds.amazonaws.com");
    db.setDatabaseName("tccnaybru");
    db.setPassword("bu381025");
    db.setUserName("brunosr");
    db.setPort(5432);
    db.open();
    query = new QSqlQuery(db);

    modelo = new QSqlTableModel(parent,db);
    modelo->setTable("tipodisp");
    modelo->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelo->select();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    ui->tableView->setModel(modelo);
}

tipoDisp::~tipoDisp()
{
    db.close();
    delete query;
    delete ui;
}

void tipoDisp::on_botaoCancelar_clicked()
{

    this->close();
}

void tipoDisp::on_botaoSalvar_clicked()
{
    ui->tableView->showColumn(1);
    int aux = 0;
    QString auxS = ui->tableView->model()->data(ui->tableView->currentIndex()).toString();

    query->prepare("SELECT id_tipo FROM tipo_d WHERE tipo = ?");
    query->addBindValue(auxS);
    query->exec();
    aux = query->value(0).toInt();
    auxS = query->lastQuery();


    query->prepare("UPDATE tipo_d SET tipo = '?', SLA = '?' WHERE id_tipo = ?");
    query->addBindValue(ui->lineTipo->text());
    query->addBindValue(ui->horasSLA->text());
    query->addBindValue(aux);
    query->exec();

    atualizaDados();
    ui->botaoSalvar->setEnabled(false);

}

void tipoDisp::on_adicionaTipo_clicked()
{
    query->prepare("INSERT INTO tipo_d (tipo, sla) VALUES (?,?)");
    query->addBindValue(ui->lineTipo->text());
    query->addBindValue(ui->horasSLA->text());
    query->exec();
    atualizaDados();
}

void tipoDisp::atualizaDados()
{
    modelo->setTable("tipodisp");
    modelo->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelo->select();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    ui->tableView->setModel(modelo);
}

void tipoDisp::on_pushButton_clicked()
{
    ui->tableView->hideColumn(1);
    ui->tableView->setModel(modelo);
    ui->botaoSalvar->setProperty("enable",true);
    ui->botaoSalvar->setEnabled(true);
}
