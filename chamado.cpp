#include "chamado.h"


using namespace std;

int chamado::getId() const
{
    return id;
}

void chamado::setId(int value)
{
    id = value;
}

m_raci chamado::getMatriz_r() const
{
    return matriz_r;
}

void chamado::setMatriz_r(const m_raci &value)
{
    matriz_r = value;
}

dispositivo chamado::getDisp() const
{
    return disp;
}

void chamado::setDisp(const dispositivo &value)
{
    disp = value;
}

float chamado::getTempo() const
{
    return tempo;
}

void chamado::setTempo(float value)
{
    tempo = value;
}

status chamado::getStat() const
{
    return stat;
}

void chamado::setStat(const status &value)
{
    stat = value;
}

bool chamado::getReincidente() const
{
    return reincidente;
}

void chamado::setReincidente(bool value)
{
    reincidente = value;
}

std::string chamado::getHora_abertura() const
{
    return hora_abertura;
}

void chamado::setHora_abertura(const std::string &value)
{
    hora_abertura = value;
}

std::string chamado::getHora_fechamento() const
{
    return hora_fechamento;
}

void chamado::setHora_fechamento(const std::string &value)
{
    hora_fechamento = value;
}

std::string chamado::getDescricao() const
{
    return descricao;
}

void chamado::setDescricao(const std::string &value)
{
    descricao = value;
}

chamado::chamado()
{
    
}
