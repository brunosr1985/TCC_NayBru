#include "dispositivo.h"

int dispositivo::getId() const
{
    return id;
}

void dispositivo::setId(int value)
{
    id = value;
}

string dispositivo::getNome() const
{
    return nome;
}

void dispositivo::setNome(const string &value)
{
    nome = value;
}

string dispositivo::getLocal() const
{
    return local;
}

void dispositivo::setLocal(const string &value)
{
    local = value;
}

tipod dispositivo::getTipo() const
{
    return tipo;
}

void dispositivo::setTipo(const tipod &value)
{
    tipo = value;
}

dispositivo::dispositivo()
{

}
