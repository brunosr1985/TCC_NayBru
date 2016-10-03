#include "status.h"

int Status::getId() const
{
    return id;
}

void Status::setId(int value)
{
    id = value;
}

int Status::getId_chamado() const
{
    return id_chamado;
}

void Status::setId_chamado(int value)
{
    id_chamado = value;
}

QString Status::getStat() const
{
    return stat;
}

void Status::setStat(const QString &value)
{
    stat = value;
}

Status::Status()
{
    
}
