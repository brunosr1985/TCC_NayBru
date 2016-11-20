#ifndef GERENCIADISPOSITIVO_H
#define GERENCIADISPOSITIVO_H

#include <QWidget>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QtGui>
#include <QMessageBox>
#include <QSqlError>
#include <QStringList>

namespace Ui {
class gerenciaDispositivo;
}

class gerenciaDispositivo : public QDialog
{
    Q_OBJECT

public:
    explicit gerenciaDispositivo(QWidget *parent = 0);
    ~gerenciaDispositivo();

private slots:
    void showEditDispositivos();

    void on_pushButton_3_clicked();

    void on_novoDisp_clicked();

    void on_toolButton_clicked();

private:
    Ui::gerenciaDispositivo *ui;
};

#endif // GERENCIADISPOSITIVO_H
