#ifndef CADASTROPESSOA_H
#define CADASTROPESSOA_H

#include <QWidget>

namespace Ui {
class Cadastropessoa;
}

class Cadastropessoa : public QWidget
{
    Q_OBJECT

public:
    explicit Cadastropessoa(QWidget *parent = 0);
    ~Cadastropessoa();

private:
    Ui::Cadastropessoa *ui;
};

#endif // CADASTROPESSOA_H