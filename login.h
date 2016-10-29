#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QtGui>
#include <QMessageBox>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_botaoNaoLoga_clicked();

    void on_botaoLogar_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
