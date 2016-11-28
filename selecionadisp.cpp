#include "selecionadisp.h"
#include "ui_selecionadisp.h"

selecionadisp::selecionadisp(QWidget *parent, int aux) :
    QDialog(parent),
    ui(new Ui::selecionadisp)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QPSQL","conn");
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

    ui->comboBox->clear();
    QString vazio = "";
    ui->comboBox->addItem(vazio);
    ui->comboBox->addItems(lista);
    ui->spinBox->setValue(aux);

}
selecionadisp::selecionadisp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selecionadisp)
{
    ui->setupUi(this);
}

selecionadisp::~selecionadisp()
{
    db.close();
    delete ui;
}



void selecionadisp::on_comboBox_currentIndexChanged(int index)
{
    QSqlQuery *query = new QSqlQuery(db);
    int auxC = ui->spinBox->value();;
    QString auxD = ui->comboBox->currentText();


    QString qry = "SELECT dispositivo.dispositivo, tipo_d.tipo, tipo_d.sla FROM tipo_d INNER JOIN dispositivo ON dispositivo.tipo = tipo_d.id_tipo WHERE dispositivo.dispositivo = '"+auxD+"'";
    //QString qry = "SELECT * FROM matriz WHERE id_chamado = "+ui->linhaChamado->text();
    QSqlQueryModel *modelo = new QSqlQueryModel();
    modelo->setQuery(qry,db);
    ui->tableDispositivos->setModel(modelo);
    ui->tableDispositivos->show();
}

void selecionadisp::on_botaoSalva_clicked()
{
    QSqlQuery *salva = new QSqlQuery(db);
    QSqlQuery *dispositivo = new QSqlQuery(db);
    QString auxD = NULL;
    int auxC = ui->spinBox->value();;

    dispositivo->exec("SELECT id_dispositivo WHERE dispositivo = '"+ui->comboBox->currentText()+"'");
    dispositivo->next();
    auxD = dispositivo->value("id_dispositivo").toString();

    salva->prepare("INSERT INTO chamxativo(id_chamado,id_ativo) VALUES (?,?)");
    salva->addBindValue(auxC);
    salva->addBindValue(auxD);
    salva->exec()            ;
}

