#ifndef M_RACI_H
#define M_RACI_H

#include "chamado.h"
#include "pessoa.h"

class m_raci
{
private:
    int id;
    bool R;
    bool A;
    bool C;
    bool I;
    pessoa pess;
    chamado cham;
public:
    m_raci();
};

#endif // M_RACI_H
