#include "selecionadisp.h"
#include "ui_selecionadisp.h"

selecionadisp::selecionadisp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selecionadisp)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","conn");
    db.setHostName("localhost");/*db.setHostName("tccnaybru.cgqgmlbbcd8e.us-west-2.rds.amazonaws.com");*/
    db.setDatabaseName("tccnaybru");
    db.setPassword("bu381025");
    db.setUserName("brunosr");
    db.setPort(5432);
    db.open();

    QSqlQuery *fillCombo = new QSqlQuery(db);
    QStringList lista;

    fillCombo->prepare("SELECT dispositivo FROM dispositivo");
    fillCombo->exec();
    while(fillCombo->next())
    {
        lista.append(fillCombo->value(0).toString());
    }
    db.close();
    ui->comboBox->clear();
    QString vazio = "";
    ui->comboBox->addItem(vazio);
    ui->comboBox->addItems(lista);

}

selecionadisp::~selecionadisp()
{
    delete ui;
}

void selecionadisp::on_comboBox_currentIndexChanged(int index)
{
    QString aux;

}
