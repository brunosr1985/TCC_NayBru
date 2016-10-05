#ifndef M_RACI_H
#define M_RACI_H

#include "pessoa.h"
#include "m_raci.h"


class MRaci
{
private:
    int id;
    bool R;
    bool A;
    bool C;
    bool I;
    pessoa pess;
//    Chamado cham;
public:
    MRaci();
    int getId() const;
    void setId(int value);
    bool getR() const;
    void setR(bool value);
    bool getA() const;
    void setA(bool value);
    bool getC() const;
    void setC(bool value);
    bool getI() const;
    void setI(bool value);
    pessoa getPess() const;
    void setPess(const pessoa &value);
};

#endif // M_RACI_H
