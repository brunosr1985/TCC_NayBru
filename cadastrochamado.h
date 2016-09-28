#ifndef CADASTROCHAMADO_H
#define CADASTROCHAMADO_H

#include <QWidget>
#include <QTableView>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QSqlDatabase>
#include <QDebug>
#include <QSql>
#include <QtCore>
#include <QtGui>
#include <QSqlError>
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtDebug>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>

namespace Ui {
class cadastrochamado;
}

class cadastrochamado : public QWidget
{
    Q_OBJECT

public:
    explicit cadastrochamado(QWidget *parent = 0);
    ~cadastrochamado();

private slots:
    void on_pushButton_3_clicked();

    void on_abreRACI_clicked();

    void on_abreDisp_clicked();

private:
    Ui::cadastrochamado *ui;
    QSqlTableModel *modelo;

};

#endif // CADASTROCHAMADO_H
