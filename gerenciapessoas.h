#ifndef GERENCIAPESSOAS_H
#define GERENCIAPESSOAS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QtGui>
#include <QMessageBox>
#include <QSqlError>
#include <QStringList>
#include <QDialog>

namespace Ui {
class gerenciaPessoas;
}

class gerenciaPessoas : public QDialog
{
    Q_OBJECT

public:
    explicit gerenciaPessoas(QWidget *parent = 0);
    ~gerenciaPessoas();

private slots:

    void on_Pessoa_Editar_clicked();

    void on_Pessoa_Salvar_clicked();

    void on_toolButton_clicked();

private:
    Ui::gerenciaPessoas *ui;
};

#endif // GERENCIAPESSOAS_H
