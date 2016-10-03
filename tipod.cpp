#include "tipod.h"

int tipod::getId() const
{
    return id;
}

void tipod::setId(int value)
{
    id = value;
}

string tipod::getTipo() const
{
    return tipo;
}

void tipod::setTipo(const string &value)
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
