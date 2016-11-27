#ifndef TIPODISP_H
#define TIPODISP_H

#include <QDialog>
#include <QWidget>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QtGui>
#include <QMessageBox>
#include <QSqlError>
#include <QStringList>
#include <QTableView>
#include <QSqlTableModel>

namespace Ui {
class tipoDisp;
}

class tipoDisp : public QDialog
{
    Q_OBJECT

public:
    explicit tipoDisp(QWidget *parent = 0);

    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *modelo;
    ~tipoDisp();

private slots:
    void on_botaoCancelar_clicked();

    void on_botaoSalvar_clicked();

    void on_adicionaTipo_clicked();

    void on_botaoEditar_clicked();

private:
    Ui::tipoDisp *ui;
    void atualizaDados();
};

#endif // TIPODISP_H
