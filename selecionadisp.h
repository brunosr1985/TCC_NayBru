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

namespace Ui {
class selecionadisp;
}

class selecionadisp : public QDialog
{
    Q_OBJECT

public:
    explicit selecionadisp(QWidget *parent = 0);
    ~selecionadisp();

private slots:
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::selecionadisp *ui;
};

#endif // SELECIONADISP_H
