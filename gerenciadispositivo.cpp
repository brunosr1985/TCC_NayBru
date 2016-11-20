#include "gerenciadispositivo.h"
#include "ui_gerenciadispositivo.h"
#include "cadastrodispositivo.h"
#include "mainwindow.h"
#include <QMdiArea>

gerenciaDispositivo::gerenciaDispositivo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gerenciaDispositivo)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","conn");
    db.setHostName("tccnaybru.cgqgmlbbcd8e.us-west-2.rds.amazonaws.com");
    db.setDatabaseName("tccnaybru");
    db.setPassword("bu381025");
    db.setUserName("brunosr");
    db.setPort(5432);
    db.open();

    QSqlQuery *fillCombo = new QSqlQuery(db);
    QStringList lista;

    fillCombo->prepare("SELECT tipo FROM tipo_d");
    fillCombo->exec();
    while(fillCombo->next())
    {
        lista.append(fillCombo->value(0).toString());
    }
    db.close();

    ui->setupUi(this);
        ui->comboTipo->clear();
    ui->comboTipo->addItems(lista);
}

gerenciaDispositivo::~gerenciaDispositivo()
{
    delete ui;
}

void gerenciaDispositivo::showEditDispositivos()
{

}

void gerenciaDispositivo::on_novoDisp_clicked()
{
    QMdiArea *md = new QMdiArea (qobject_cast<QMdiArea *>(parent()));
    JanelaPrincipal *jp = new JanelaPrincipal (qobject_cast<JanelaPrincipal *>(parent()));
    cadastrodispositivo *cd = new cadastrodispositivo();
    jp->setCentralWidget(md);
    cd->setAttribute(Qt::WA_DeleteOnClose);
    md->addSubWindow(cd);
    md->show();
    cd->show();
    this->~gerenciaDispositivo();
}

void gerenciaDispositivo::on_pushButton_3_clicked()
{
    delete parent();
}

void gerenciaDispositivo::on_toolButton_clicked()
{
    int aux;

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","conn");
    db.setHostName("tccnaybru.cgqgmlbbcd8e.us-west-2.rds.amazonaws.com");
    db.setDatabaseName("tccnaybru");
    db.setPassword("bu381025");
    db.setUserName("brunosr");
    db.setPort(5432);
    db.open();

    QSqlQuery *query = new QSqlQuery(db);
    query->prepare("SELECT dispositivo FROM dispositivo WHERE id_dispositivo = ?");
    query->addBindValue(ui->lineID->text().toInt());
    query->exec();
    query->next();
    ui->lineNome->setText(query->value(0).toString());
    ui->lineNome->update();

    query->prepare("SELECT tipo FROM dispositivo WHERE id_dispositivo = ?");
    query->addBindValue(ui->lineID->text().toInt());
    query->exec();
    query->next();
    aux = query->value(0).toInt();
    query->prepare("SELECT tipo FROM tipo_d WHERE id_tipo = ?");
    query->addBindValue(aux);
    query->exec();
    query->next();
    ui->comboTipo->setCurrentIndex(ui->comboTipo->findText(query->value(0).toString()));
    ui->comboTipo->update();

    query->prepare("SELECT local FROM dispositivo WHERE id_dispositivo = ?");
    query->addBindValue(ui->lineID->text().toInt());
    query->exec();
    query->next();
    ui->lineLocal->setText(query->value(0).toString());
    ui->lineLocal->update();
}
