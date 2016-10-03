#ifndef CHAMADO_H
#define CHAMADO_H

#include "status.h"
#include "dispositivo.h"
#include "m_raci.h"
#include <string>

class chamado
{
private:
    int id;
    m_raci matriz_r;
    dispositivo disp;
    float tempo;
    status stat;
    bool reincidente;
    std::string hora_abertura;
    std::string hora_fechamento;
    std::string descricao;

public:

    chamado();

    int getId() const;
    void setId(int value);
    m_raci getMatriz_r() const;
    void setMatriz_r(const m_raci &value);
    dispositivo getDisp() const;
    void setDisp(const dispositivo &value);
    float getTempo() const;
    void setTempo(float value);
    status getStat() const;
    void setStat(const status &value);
    bool getReincidente() const;
    void setReincidente(bool value);
    std::string getHora_abertura() const;
    void setHora_abertura(const std::string &value);
    std::string getHora_fechamento() const;
    void setHora_fechamento(const std::string &value);
    std::string getDescricao() const;
    void setDescricao(const std::string &value);
};

#endif // CHAMADO_H
