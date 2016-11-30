#ifndef RELATORIOSIMPLES_H
#define RELATORIOSIMPLES_H

#include <QWidget>
#include <QTableView>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDialog>

namespace Ui {
class relatoriosimples;
}

class relatoriosimples : public QWidget
{
    Q_OBJECT

public:
    explicit relatoriosimples(QWidget *parent = 0);
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlQueryModel *modelo;
    ~relatoriosimples();

private slots:


    void on_botaoAtivos_clicked();

    void on_botaoPessoas_clicked();

    void on_botaoChamados_clicked();

private:
    Ui::relatoriosimples *ui;
    void atualizadados(QString tabela);
};

#endif // RELATORIOSIMPLES_H
