#include "pessoa.h"

int pessoa::getId() const
{
    return id;
}

void pessoa::setId(int value)
{
    id = value;
}

string pessoa::getNome() const
{
    return nome;
}

void pessoa::setNome(const string &value)
{
    nome = value;
}

string pessoa::getTelefone() const
{
    return telefone;
}

void pessoa::setTelefone(const string &value)
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

string pessoa::getEmail() const
{
    return email;
}

void pessoa::setEmail(const string &value)
{
    email = value;
}

string pessoa::getDepto() const
{
    return depto;
}

void pessoa::setDepto(const string &value)
{
    depto = value;
}

string pessoa::getCargo() const
{
    return cargo;
}

void pessoa::setCargo(const string &value)
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
