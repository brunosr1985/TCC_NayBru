#ifndef GERENCIAPESSOAS_H
#define GERENCIAPESSOAS_H

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

private:
    Ui::gerenciaPessoas *ui;
};

#endif // GERENCIAPESSOAS_H
