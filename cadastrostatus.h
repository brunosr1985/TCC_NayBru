#ifndef CADASTROSTATUS_H
#define CADASTROSTATUS_H

#include <QWidget>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDialog>

namespace Ui {
class cadastrostatus;
}

class cadastrostatus : public QDialog
{
    Q_OBJECT

public:
    explicit cadastrostatus(QWidget *parent = 0);
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *modelo;
    ~cadastrostatus();

private slots:
    void on_Adicionar_clicked();


    void on_botaoEditar_clicked();

    void on_botaoInativo_clicked();

private:
    Ui::cadastrostatus *ui;
    void atualizaDados();
};

#endif // CADASTROSTATUS_H
