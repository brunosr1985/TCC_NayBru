#ifndef CADASTRODISPOSITIVO_H
#define CADASTRODISPOSITIVO_H

#include <QWidget>

namespace Ui {
class cadastrodispositivo;
}

class cadastrodispositivo : public QWidget
{
    Q_OBJECT

public:
    explicit cadastrodispositivo(QWidget *parent = 0);
    ~cadastrodispositivo();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::cadastrodispositivo *ui;
};

#endif // CADASTRODISPOSITIVO_H
