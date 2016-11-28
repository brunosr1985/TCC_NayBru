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
    modelo->setTable("relat_cham");
    modelo->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelo->select();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    ui->tableView->setModel(modelo);
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
        atualizadados("relat_ativos");
    }
    else if(aux == "Pessoas")
    {
       atualizadados("relat_pessoas");
    }
    else if(aux == "Chamados")
    {
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

void relatorioSimples::on_comboBox_activated(const QString &arg1)
{
    QString aux = ui->comboBox->currentText();
    int select = 0;

    if(aux == "Ativos")
    {
        atualizadados("relat_ativos");
    }else if(aux == "Pessoas")
    {
         atualizadados("relat_pessoas");
    }else if(aux == "Chamados")
    {
       atualizadados("relat_cham");
    }
}
