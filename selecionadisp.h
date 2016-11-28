#ifndef SELECIONADISP_H
#define SELECIONADISP_H

#include <QWidget>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QtGui>
#include <QMessageBox>
#include <QSqlError>
#include <QDialog>
#include <QSqlQueryModel>


namespace Ui {
class selecionadisp;
}

class selecionadisp : public QDialog
{
    Q_OBJECT

public:
    explicit selecionadisp(QWidget *parent = 0);
    selecionadisp(QWidget *parent = 0, int aux = 0);
    QSqlDatabase db;
    ~selecionadisp();

private slots:


    void on_comboBox_currentIndexChanged(int index);

    void on_botaoSalva_clicked();

private:
    Ui::selecionadisp *ui;

};

#endif // SELECIONADISP_H
