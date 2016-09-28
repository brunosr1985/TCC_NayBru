#ifndef SELECIONAEQUIP_H
#define SELECIONAEQUIP_H

#include <QDialog>

namespace Ui {
class selecionaequip;
}

class selecionaequip : public QDialog
{
    Q_OBJECT

public:
    explicit selecionaequip(QWidget *parent = 0);
    ~selecionaequip();

private:
    Ui::selecionaequip *ui;
};

#endif // SELECIONAEQUIP_H
