#ifndef STATUS_H
#define STATUS_H

//#include "chamado.h"
#include "status.h"

#include <QString>

class Status
{
private:
    int id;
    int id_chamado;
    QString stat;
public:
    Status();
    int getId() const;
    void setId(int value);
    int getId_chamado() const;
    void setId_chamado(int value);
    QString getStat() const;
    void setStat(const QString &value);
};

#endif // STATUS_H
