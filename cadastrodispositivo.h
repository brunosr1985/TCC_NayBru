#ifndef CADASTRODISPOSITIVO_H
#define CADASTRODISPOSITIVO_H

#include <QWidget>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QtGui>
#include <QMessageBox>
#include <QSqlError>
#include <QStringList>

namespace Ui {
class cadastrodispositivo;
}

class cadastrodispositivo : public QWidget
{
    Q_OBJECT

public:
    explicit cadastrodispositivo(QWidget *parent = 0);
    void atualizadados();
    ~cadastrodispositivo();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();


    void on_botaoAtualizar_clicked();

    void on_botaoNovo_clicked();

private:
    Ui::cadastrodispositivo *ui;

};

#endif // CADASTRODISPOSITIVO_H

