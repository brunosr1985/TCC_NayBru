#include "relatoriosimples.h"
#include "ui_relatoriosimples.h"

relatorioSimples::relatorioSimples(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::relatorioSimples)
{
    ui->setupUi(this);
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
}

relatorioSimples::~relatorioSimples()
{
    delete ui;
}

void relatorioSimples::on_comboBox_currentIndexChanged(int index)
{
    QString aux = ui->comboBox->currentText();
    int select = 0;

    if(aux == "Ativos")
    {
        select = 1;
    }else if(aux == "Pessoas")
    {
        select = 2;
    }else if(aux == "Chamados")
    {
        select = 3;
    }

    switch(select)
    {
    case 1:

    case 2:

    case 3:
        atualizadados("relat_cham");
    }
}

void relatorioSimples::atualizadados(QString aux)
{
    modelo->setTable(aux);
    modelo->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelo->select();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    ui->tableView->setModel(modelo);
}
