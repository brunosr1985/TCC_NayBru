#ifndef CADASTROPESSOA_H
#define CADASTROPESSOA_H

#include <QWidget>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QtGui>
#include <QMessageBox>
#include <QSqlError>

namespace Ui {
class Cadastropessoa;
}

class Cadastropessoa : public QWidget
{
    Q_OBJECT

public:
    explicit Cadastropessoa(QWidget *parent = 0);
    ~Cadastropessoa();

private slots:
    void on_Novo_Grupo_clicked();

    void on_Pessoa_Salvar_clicked();

private:
    Ui::Cadastropessoa *ui;
};

#endif // CADASTROPESSOA_H
