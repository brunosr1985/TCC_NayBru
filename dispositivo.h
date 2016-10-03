

#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H

#include "tipod.h"
#include "dispositivo.h"

#include <QString>

class Dispositivo
{
private:
    int id;
    QString nome;
    QString local;
    tipod tipo;

public:

    Dispositivo();
    int getId() const;
    void setId(int value);
    QString getNome() const;
    void setNome(const QString &value);
    QString getLocal() const;
    void setLocal(const QString &value);
    tipod getTipo() const;
    void setTipo(const tipod &value);
};

#endif // DISPOSITIVO_H
