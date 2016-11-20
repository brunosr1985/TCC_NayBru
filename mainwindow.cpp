#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gerenciapessoas.h"
#include "gerenciadispositivo.h"
#include "gerenciachamados.h"
#include "cadastropessoa.h"
#include "cadastrochamado.h"
#include "cadastrodispositivo.h"
#include "novogrupo.h"
#include "tipodisp.h"

JanelaPrincipal::JanelaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::JanelaPrincipal)
{
    ui->setupUi(this);
}

JanelaPrincipal::~JanelaPrincipal()
{
    delete ui;
}

void JanelaPrincipal::on_actionPessoas_x_Chamados_triggered()
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

void JanelaPrincipal::on_actionChamados_2_triggered()
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

void JanelaPrincipal::on_actionPessoas_x_Qtde_Chamados_triggered()
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

void JanelaPrincipal::on_actionChamados_triggered()
{
    /*gerenciaChamados *gc = new gerenciaChamados(ui->mdiArea);
    ui->mdiArea->addSubWindow(gc);
    gc->show();*/
}

void JanelaPrincipal::on_actionDispositivos_triggered()
{
    QMdiArea *md = new QMdiArea(this);
    this->setCentralWidget(md);
    gerenciaDispositivo *gd = new gerenciaDispositivo(md);
    gd->setAttribute(Qt::WA_DeleteOnClose);
    md->addSubWindow(gd);
    gd->show();
}

void JanelaPrincipal::on_actionPessoas_triggered()
{
    /*gerenciaPessoas *gp = new gerenciaPessoas(ui->mdiArea);\
    ui->mdiArea->addSubWindow(gp);
    gp->show();*/
}


void JanelaPrincipal::on_actionPessoas_2_triggered()
{
    QMdiArea *md = new QMdiArea(this);
    this->setCentralWidget(md);
    Cadastropessoa *cp = new Cadastropessoa(md);
    cp->setAttribute(Qt::WA_DeleteOnClose);
    md->addSubWindow(cp);
    cp->show();
}

void JanelaPrincipal::on_actionDispositivos_3_triggered()
{
    QMdiArea *md = new QMdiArea(this);
    this->setCentralWidget(md);
    cadastrodispositivo *cd = new cadastrodispositivo(md);
    cd->setAttribute(Qt::WA_DeleteOnClose);
    md->addSubWindow(cd);
    cd->show();
}

void JanelaPrincipal::on_actionChamados_3_triggered()
{
    QMdiArea *md = new QMdiArea(this);
    this->setCentralWidget(md);
    cadastrochamado *cc = new cadastrochamado(md);
    cc->setAttribute(Qt::WA_DeleteOnClose);
    md->addSubWindow(cc);
    cc->show();
}
