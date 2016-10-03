#include "chamado.h"

int Chamado::getId() const
{
    return id;
}

void Chamado::setId(int value)
{
    id = value;
}

MRaci Chamado::getMatriz_r() const
{
    return matriz_r;
}

void Chamado::setMatriz_r(const MRaci &value)
{
    matriz_r = value;
}

Dispositivo Chamado::getDisp() const
{
    return disp;
}

void Chamado::setDisp(const Dispositivo &value)
{
    disp = value;
}

float Chamado::getTempo() const
{
    return tempo;
}

void Chamado::setTempo(float value)
{
    tempo = value;
}

Status Chamado::getStat() const
{
    return stat;
}

void Chamado::setStat(const Status &value)
{
    stat = value;
}

bool Chamado::getReincidente() const
{
    return reincidente;
}

void Chamado::setReincidente(bool value)
{
    reincidente = value;
}

QString Chamado::getHora_abertura() const
{
    return hora_abertura;
}

void Chamado::setHora_abertura(const QString &value)
{
    hora_abertura = value;
}

QString Chamado::getHora_fechamento() const
{
    return hora_fechamento;
}

void Chamado::setHora_fechamento(const QString &value)
{
    hora_fechamento = value;
}

QString Chamado::getDescricao() const
{
    return descricao;
}

void Chamado::setDescricao(const QString &value)
{
    descricao = value;
}

Chamado::Chamado()
{
    
}
