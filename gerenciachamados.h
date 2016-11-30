#ifndef GERENCIACHAMADOS_H
#define GERENCIACHAMADOS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QString>
#include <QSqlQuery>
#include <QtGui>
#include <QMessageBox>
#include <QSqlError>
#include <QStringList>
#include "matrizraci.h"
#include "selecionadisp.h"

namespace Ui {
class gerenciaChamados;
}

class gerenciaChamados : public QDialog
{
    Q_OBJECT

public:
    explicit gerenciaChamados(QWidget *parent = 0);
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *modelo;
    ~gerenciaChamados();

private slots:
    void on_adicionaAcompanhamento_clicked();
    void atualizadados();
    void on_toolButton_clicked();

    void on_abreRACI_clicked();

    void on_abreDisp_clicked();

private:
    Ui::gerenciaChamados *ui;
};

#endif // GERENCIACHAMADOS_H
