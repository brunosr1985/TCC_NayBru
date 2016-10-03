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
    int getId() const;
    void setId(int value);
    string getNome() const;
    void setNome(const string &value);
    string getTelefone() const;
    void setTelefone(const string &value);
    int getRamal() const;
    void setRamal(int value);
    string getEmail() const;
    void setEmail(const string &value);
    string getDepto() const;
    void setDepto(const string &value);
    string getCargo() const;
    void setCargo(const string &value);
    int getGrupo() const;
    void setGrupo(int value);
};

#endif // PESSOA_H
