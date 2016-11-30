#ifndef CADASTROUSUARIO_H
#define CADASTROUSUARIO_H

#include <QDialog>
#include <QWidget>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QtGui>
#include <QMessageBox>
#include <QSqlError>
#include <QStringList>
#include <QSqlTableModel>

namespace Ui {
class cadastrousuario;
}

class cadastrousuario : public QDialog
{
    Q_OBJECT

public:
    explicit cadastrousuario(QWidget *parent = 0);
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *modelo;
    ~cadastrousuario();

private slots:
    void on_botaoNovo_clicked();
    void on_alteraSenha_clicked();
    void atualizadados();

private:
    Ui::cadastrousuario *ui;
};

#endif // CADASTROUSUARIO_H
