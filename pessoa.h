#ifndef PESSOA_H
#define PESSOA_H

#include "grupop.h"
#include <QString>


class pessoa
{
public:
    int id;
    QString nome;
    QString telefone;
    int ramal;
    QString email;
    QString depto;
    QString cargo;
    GrupoP grupo;

    pessoa();
    int getId() const;
    void setId(int value);
    QString getNome() const;
    void setNome(const QString &value);
    QString getTelefone() const;
    void setTelefone(const QString &value);
    int getRamal() const;
    void setRamal(int value);
    QString getEmail() const;
    void setEmail(const QString &value);
    QString getDepto() const;
    void setDepto(const QString &value);
    QString getCargo() const;
    void setCargo(const QString &value);
    int getGrupo() const;
    void setGrupo(int value);
};

#endif // PESSOA_H
