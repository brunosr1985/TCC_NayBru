

#include "m_raci.h"

int MRaci::getId() const
{
    return id;
}

void MRaci::setId(int value)
{
    id = value;
}

bool MRaci::getR() const
{
    return R;
}

void MRaci::setR(bool value)
{
    R = value;
}

bool MRaci::getA() const
{
    return A;
}

void MRaci::setA(bool value)
{
    A = value;
}

bool MRaci::getC() const
{
    return C;
}

void MRaci::setC(bool value)
{
    C = value;
}

bool MRaci::getI() const
{
    return I;
}

void MRaci::setI(bool value)
{
    I = value;
}

pessoa MRaci::getPess() const
{
    return pess;
}

void MRaci::setPess(const pessoa &value)
{
    pess = value;
}

MRaci::MRaci()
{
    
}
