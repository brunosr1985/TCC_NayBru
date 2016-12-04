#ifndef NOVOGRUPO_H
#define NOVOGRUPO_H

#include <QWidget>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDialog>

namespace Ui {
class novoGrupo;
}

class novoGrupo : public QWidget
{
    Q_OBJECT

public:
    explicit novoGrupo(QWidget *parent = 0);
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *modelo;
    ~novoGrupo();

private slots:
    void on_pushButton_2_clicked();
    void on_Adicionar_clicked();
    void on_botaoEditar_clicked();
    void on_botaoAtualizar_clicked();
    void on_botaoInativo_clicked();

private:
    Ui::novoGrupo *ui;
    void atualizaDados();
};

#endif // NOVOGRUPO_H
