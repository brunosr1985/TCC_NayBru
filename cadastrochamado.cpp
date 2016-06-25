#include "cadastrochamado.h"
#include "ui_cadastrochamado.h"
#include "matrizraci.h"



cadastrochamado::cadastrochamado(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cadastrochamado)
{
    ui->setupUi(this);
}

cadastrochamado::~cadastrochamado()
{
    delete ui;
}

void cadastrochamado::on_pushButton_3_clicked()
{

}

void cadastrochamado::on_abreRACI_clicked()
{
    QString erro;
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","conn");
    db.setHostName("localhost");
    db.setDatabaseName("TCC");
    db.setPassword("raciuser");
    db.setUserName("raci");
    db.setPort(5432);
    erro = db.open("raciuser","raci");


    modelo = new QSqlTableModel(parent(),db);

    modelo->setTable("raci");
    modelo->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelo->select();
    QTableView *matriz = new QTableView;
    //pessxqtde->setEditTriggers(QAbstractItemView::NoEditTriggers);
    matriz->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    matriz->setModel(modelo);
    matriz->show();
    db.close();
}
