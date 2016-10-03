#include "grupop.h"

int GrupoP::getId() const
{
    return id;
}

void GrupoP::setId(int value)
{
    id = value;
}

QString GrupoP::getNome() const
{
    return nome;
}

void GrupoP::setNome(const QString &value)
{
    nome = value;
}

GrupoP::GrupoP()
{

}
