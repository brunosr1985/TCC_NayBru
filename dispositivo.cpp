#include "dispositivo.h"

int Dispositivo::getId() const
{
    return id;
}

void Dispositivo::setId(int value)
{
    id = value;
}

QString Dispositivo::getNome() const
{
    return nome;
}

void Dispositivo::setNome(const QString &value)
{
    nome = value;
}

QString Dispositivo::getLocal() const
{
    return local;
}

void Dispositivo::setLocal(const QString &value)
{
    local = value;
}

tipod Dispositivo::getTipo() const
{
    return tipo;
}

void Dispositivo::setTipo(const tipod &value)
{
    tipo = value;
}

Dispositivo::Dispositivo()
{

}
