#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H

#include <string>
#include "tipod.h"


class dispositivo
{
private:
    int id;
    string nome;
    string local;
    tipod tipo;

public:

    dispositivo();
    int getId() const;
    void setId(int value);
    string getNome() const;
    void setNome(const string &value);
    string getLocal() const;
    void setLocal(const string &value);
    tipod getTipo() const;
    void setTipo(const tipod &value);
};

#endif // DISPOSITIVO_H
