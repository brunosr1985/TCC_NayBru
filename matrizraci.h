#ifndef MATRIZRACI_H
#define MATRIZRACI_H

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

namespace Ui {
class matrizRACI;
}

class matrizRACI : public QWidget
{
    Q_OBJECT

public:
    explicit matrizRACI(QWidget *parent = 0);
    ~matrizRACI();

private slots:
    void on_raciCarregar_clicked();

private:
    Ui::matrizRACI *ui;
    QSqlTableModel *modelo;
};

#endif // MATRIZRACI_H
