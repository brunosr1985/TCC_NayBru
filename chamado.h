#ifndef CHAMADO_H
#define CHAMADO_H

#include "status.h"
#include "dispositivo.h"
#include "m_raci.h"
//#include "chamado.h"

#include <QString>

class Chamado
{
private:
    int id;
    MRaci matriz_r;
    Dispositivo disp;
    float tempo;
    Status stat;
    bool reincidente;
    QString hora_abertura;
    QString hora_fechamento;
    QString descricao;

public:

    Chamado();

    int getId() const;
    void setId(int value);
    MRaci getMatriz_r() const;
    void setMatriz_r(const MRaci &value);
    Dispositivo getDisp() const;
    void setDisp(const Dispositivo &value);
    float getTempo() const;
    void setTempo(float value);
    Status getStat() const;
    void setStat(const Status &value);
    bool getReincidente() const;
    void setReincidente(bool value);
    QString getHora_abertura() const;
    void setHora_abertura(const QString &value);
    QString getHora_fechamento() const;
    void setHora_fechamento(const QString &value);
    QString getDescricao() const;
    void setDescricao(const QString &value);
};

#endif // CHAMADO_H
