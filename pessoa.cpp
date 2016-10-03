#include "pessoa.h"

int pessoa::getId() const
{
    return id;
}

void pessoa::setId(int value)
{
    id = value;
}

QString pessoa::getNome() const
{
    return nome;
}

void pessoa::setNome(const QString &value)
{
    nome = value;
}

QString pessoa::getTelefone() const
{
    return telefone;
}

void pessoa::setTelefone(const QString &value)
{
    telefone = value;
}

int pessoa::getRamal() const
{
    return ramal;
}

void pessoa::setRamal(int value)
{
    ramal = value;
}

QString pessoa::getEmail() const
{
    return email;
}

void pessoa::setEmail(const QString &value)
{
    email = value;
}

QString pessoa::getDepto() const
{
    return depto;
}

void pessoa::setDepto(const QString &value)
{
    depto = value;
}

QString pessoa::getCargo() const
{
    return cargo;
}

void pessoa::setCargo(const QString &value)
{
    cargo = value;
}

int pessoa::getGrupo() const
{
    return grupo;
}

void pessoa::setGrupo(int value)
{
    grupo = value;
}

pessoa::pessoa()
{
    
}
