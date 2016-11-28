#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gerenciadispositivo.h"
#include <QMainWindow>
#include <QTableView>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QSqlDatabase>
#include <QDebug>
#include <QSql>
#include <QtCore>
#include <QtGui>
#include <QSqlError>
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtDebug>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QMdiArea>

namespace Ui {
class JanelaPrincipal;
class CadastroPess;
}

class JanelaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit JanelaPrincipal(QWidget *parent = 0);
    ~JanelaPrincipal();



private slots:
    void on_actionPessoas_x_Chamados_triggered();

    void on_actionChamados_2_triggered();

    void on_actionPessoas_x_Qtde_Chamados_triggered();

    void on_actionChamados_triggered();

    void on_actionDispositivos_triggered();

    void on_actionPessoas_triggered();

    void on_actionPessoas_2_triggered();

    void on_actionDispositivos_3_triggered();

    void on_actionChamados_3_triggered();

    void on_actionCriar_Usu_rio_triggered();

    void on_actionCriar_Status_triggered();

    void on_actionCriar_Prioridade_triggered();

    void on_actionSimples_triggered();

private:
    Ui::JanelaPrincipal *ui;
    QSqlTableModel *modelo;
    QSqlQueryModel *query;
};



#endif // MAINWINDOW_H
