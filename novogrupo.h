#ifndef NOVOGRUPO_H
#define NOVOGRUPO_H

#include <QWidget>

namespace Ui {
class novoGrupo;
}

class novoGrupo : public QWidget
{
    Q_OBJECT

public:
    explicit novoGrupo(QWidget *parent = 0);
    ~novoGrupo();

private:
    Ui::novoGrupo *ui;
};

#endif // NOVOGRUPO_H
