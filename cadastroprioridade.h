#ifndef CADASTROPRIORIDADE_H
#define CADASTROPRIORIDADE_H

#include <QWidget>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDialog>


namespace Ui {
class cadastroprioridade;
}

class cadastroprioridade : public QDialog
{
    Q_OBJECT

public:
    explicit cadastroprioridade(QWidget *parent = 0);
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *modelo;
    ~cadastroprioridade();

private slots:
    void on_botaoAdicionar_clicked();

    void on_botaoEditar_clicked();

    void on_botaoInativo_clicked();

private:
    Ui::cadastroprioridade *ui;
    void atualizaDados();
};

#endif // CADASTROPRIORIDADE_H
