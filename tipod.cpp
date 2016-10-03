#include "tipod.h"

int tipod::getId() const
{
    return id;
}

void tipod::setId(int value)
{
    id = value;
}

QString tipod::getTipo() const
{
    return tipo;
}

void tipod::setTipo(const QString &value)
{
    tipo = value;
}

float tipod::getSLA() const
{
    return SLA;
}

void tipod::setSLA(float value)
{
    SLA = value;
}

tipod::tipod()
{

}
