#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gerenciapessoas.h"
#include "gerenciadispositivo.h"
#include "gerenciachamados.h"
#include "novogrupo.h"
#include "tipodisp.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionPessoas_x_Chamados_triggered()
{

    QString erro;
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","conn");
    db.setHostName("localhost");
    db.setDatabaseName("postgres");
    db.setPassword("bu381025");
    db.setUserName("tccnaybru");
    db.setPort(5432);
    erro = db.open("postgres","bu381025");

//pessxchamado
    modelo = new QSqlTableModel(parent(),db);

    modelo->setTable("pessxchamado");
    modelo->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelo->select();
    QTableView *pessxcham = new QTableView;
    pessxcham->setEditTriggers(QAbstractItemView::NoEditTriggers);
    pessxcham->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    pessxcham->setModel(modelo);
    pessxcham->show();
    db.close();

}

void MainWindow::on_actionChamados_2_triggered()
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

    modelo->setTable("chamados1");
    modelo->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelo->select();
    QTableView *chamados = new QTableView;
    chamados->setEditTriggers(QAbstractItemView::NoEditTriggers);
    chamados->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    chamados->setModel(modelo);
    chamados->show();
    db.close();

}

void MainWindow::on_actionPessoas_x_Qtde_Chamados_triggered()
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

    modelo->setTable("pessxqtde");
    modelo->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelo->select();
    QTableView *pessxqtde = new QTableView;
    pessxqtde->setEditTriggers(QAbstractItemView::NoEditTriggers);
    pessxqtde->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    pessxqtde->setModel(modelo);
    pessxqtde->show();
    db.close();
}

void MainWindow::on_actionChamados_triggered()
{
    gerenciaChamados *gc = new gerenciaChamados();
    gc->show();
}

void MainWindow::on_actionDispositivos_triggered()
{
    gerenciaDispositivo *gd = new gerenciaDispositivo();
    gd->show();
}

void MainWindow::on_actionPessoas_triggered()
{
    gerenciaPessoas *gp = new gerenciaPessoas();
    gp->show();
}

void MainWindow::on_actionNovo_Grupo_de_Pessoas_triggered()
{
    novoGrupo *ng = new novoGrupo();
    ng->show();
}

void MainWindow::on_actionNovo_Tipo_de_Dispositivo_triggered()
{
    tipoDisp *td = new tipoDisp();
    td->show();
}
