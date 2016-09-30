#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

namespace Ui {
class MainWindow;
class CadastroPess;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionPessoa_triggered();

    void on_actionChamado_triggered();

    void on_actionDispositivo_triggered();

    void on_actionPessoas_x_Chamados_triggered();

    void on_actionChamados_2_triggered();

    void on_actionPessoas_x_Qtde_Chamados_triggered();

    void on_actionChamados_triggered();

    void on_actionDispositivos_triggered();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *modelo;
    QSqlQueryModel *query;
};



#endif // MAINWINDOW_H
