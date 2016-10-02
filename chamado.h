#ifndef CHAMADO_H
#define CHAMADO_H

#include "status.h"
#include "dispositivo.h"
#include "m_raci.h"
#include <string>

class chamado
{

public:
    int id;
    m_raci matriz_r;
    dispositivo disp;
    float tempo;
    float sla = disp.sla;
    status stat;
    bool reincidente;
    std::string hora_abertura;
    std::string hora_fechamento;
    std::string descricao;

    chamado();

};

#endif // CHAMADO_H
