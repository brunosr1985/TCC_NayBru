#ifndef RELATORIOSIMPLES_H
#define RELATORIOSIMPLES_H

#include <QDialog>
#include <QWidget>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDialog>

namespace Ui {
class relatorioSimples;
}

class relatorioSimples : public QDialog
{
    Q_OBJECT

public:
    explicit relatorioSimples(QWidget *parent = 0);
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *modelo;
    ~relatorioSimples();

private slots:
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::relatorioSimples *ui;
    void atualizadados(QString tabela);
};

#endif // RELATORIOSIMPLES_H
