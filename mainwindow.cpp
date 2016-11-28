#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gerenciapessoas.h"
#include "gerenciadispositivo.h"
#include "gerenciachamados.h"
#include "cadastropessoa.h"
#include "cadastrochamado.h"
#include "cadastrodispositivo.h"
#include "cadastroprioridade.h"
#include "cadastrostatus.h"
#include "cadastrousuario.h"
#include "novogrupo.h"
#include "tipodisp.h"
#include "relatoriosimples.h"

JanelaPrincipal::JanelaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::JanelaPrincipal)
{
    ui->setupUi(this);


    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","conn");
    db.setHostName("localhost");/*db.setHostName("tccnaybru.cgqgmlbbcd8e.us-west-2.rds.amazonaws.com");*/
    db.setDatabaseName("tccnaybru");
    db.setPassword("bu381025");
    db.setUserName("brunosr");
    db.setPort(5432);
    db.open();

    QSqlQuery *permissao = new QSqlQuery(db);
    bool administrativo;

    permissao->exec("SELECT situacao FROM permissoes WHERE permissao = 'administrativo'");
    permissao->first();
    administrativo = permissao->value("situacao").toBool();
    if(!administrativo)
    {
        ui->menuArquivo->setEnabled(false);
    }

 }

JanelaPrincipal::~JanelaPrincipal()
{
    delete ui;
}

void JanelaPrincipal::on_actionPessoas_x_Chamados_triggered()
{


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
    QMdiArea *md = new QMdiArea(this);
    this->setCentralWidget(md);
    gerenciaPessoas *gp = new gerenciaPessoas(md);
    gp->setAttribute(Qt::WA_DeleteOnClose);
    md->addSubWindow(gp);
    gp->show();
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

void JanelaPrincipal::on_actionCriar_Usu_rio_triggered()
{
    QMdiArea *md = new QMdiArea(this);
    this->setCentralWidget(md);
    cadastrousuario *cu = new cadastrousuario(md);
    cu->setAttribute(Qt::WA_DeleteOnClose);
    md->addSubWindow(cu);
    cu->show();
}

void JanelaPrincipal::on_actionCriar_Status_triggered()
{
    QMdiArea *md = new QMdiArea(this);
    this->setCentralWidget(md);
    cadastrostatus *cs = new cadastrostatus(md);
    cs->setAttribute(Qt::WA_DeleteOnClose);
    md->addSubWindow(cs);
    cs->show();
}

void JanelaPrincipal::on_actionCriar_Prioridade_triggered()
{
    QMdiArea *md = new QMdiArea(this);
    this->setCentralWidget(md);
    cadastroprioridade *cpr = new cadastroprioridade(md);
    cpr->setAttribute(Qt::WA_DeleteOnClose);
    md->addSubWindow(cpr);
    cpr->show();
}

void JanelaPrincipal::on_actionSimples_triggered()
{
    QMdiArea *md = new QMdiArea(this);
    this->setCentralWidget(md);
    relatorioSimples *rs = new relatorioSimples(md);
    rs->setAttribute(Qt::WA_DeleteOnClose);
    md->addSubWindow(rs);
    rs->show();
}
