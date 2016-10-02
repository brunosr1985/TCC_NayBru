#ifndef PESSOA_H
#define PESSOA_H

#include <string>

using namespace std;

class pessoa
{
public:
    int id;
    string nome;
    string telefone;
    int ramal;
    string email;
    string depto;
    string cargo;
    int grupo;

    pessoa();
};

#endif // PESSOA_H
