#ifndef CADASTROPRIORIDADE_H
#define CADASTROPRIORIDADE_H

#include <QDialog>

namespace Ui {
class cadastroprioridade;
}

class cadastroprioridade : public QDialog
{
    Q_OBJECT

public:
    explicit cadastroprioridade(QWidget *parent = 0);
    ~cadastroprioridade();

private:
    Ui::cadastroprioridade *ui;
};

#endif // CADASTROPRIORIDADE_H
