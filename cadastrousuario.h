#ifndef CADASTROUSUARIO_H
#define CADASTROUSUARIO_H

#include <QDialog>

namespace Ui {
class cadastrousuario;
}

class cadastrousuario : public QDialog
{
    Q_OBJECT

public:
    explicit cadastrousuario(QWidget *parent = 0);
    ~cadastrousuario();

private:
    Ui::cadastrousuario *ui;
};

#endif // CADASTROUSUARIO_H
