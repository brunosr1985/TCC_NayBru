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
    db.setDatabaseName("postgres");
    db.setPassword("bu381025");
    db.setUserName("tccnaybru");
    db.setPort(5432);
    erro = db.open("postgres","bu381025");


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
