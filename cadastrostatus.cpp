#include "cadastrostatus.h"
#include "ui_cadastrostatus.h"

cadastrostatus::cadastrostatus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastrostatus)
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

cadastrostatus::~cadastrostatus()
{
    delete ui;
}

void cadastrostatus::on_Adicionar_clicked()
{
    query->prepare("INSERT INTO status (estado) VALUES (?)");
    query->addBindValue(ui->lineStatus->text());
    query->exec();
    atualizaDados();


    /*if(query->exec())
       {
        QMessageBox messageBox;
        messageBox.critical(0,"Sucesso!","Cadastro realizado com sucesso");
        messageBox.setFixedSize(500,200);
        db.close();
    }
    else
    {
        erro = query->lastError().text();
        QMessageBox messageBox;
        messageBox.critical(0,"Erro!",erro);
        messageBox.setFixedSize(500,200);

    }*/
}

void cadastrostatus::on_botaoEditar_clicked()
{
     int aux;
     QString auxS = ui->tableStatus->model()->data(ui->tableStatus->currentIndex()).toString();
     QString aux2 = ui->lineStatus->text();

     query->exec("SELECT id_estado FROM status WHERE estado = '"+auxS+"'");
     query->next();
     aux = query->value("id_estado").toInt();

     query->prepare("UPDATE status SET estado = ? WHERE id_estado = ? OR estado = ?");
     query->addBindValue(aux2);
     query->addBindValue(aux);
     query->addBindValue(auxS);
     query->exec();

    atualizaDados();

}

void cadastrostatus::atualizaDados()
{
    modelo->setTable("view_status");
    modelo->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelo->select();
    ui->tableStatus->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableStatus->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    ui->tableStatus->setModel(modelo);
}

void cadastrostatus::on_botaoInativo_clicked()
{

}
