#ifndef TIPOD_H
#define TIPOD_H

#include <QString>


class tipod
{
private:
    int id;
    QString tipo;
    float SLA;

public:

    tipod();
    int getId() const;
    void setId(int value);
    QString getTipo() const;
    void setTipo(const QString &value);
    float getSLA() const;
    void setSLA(float value);
};

#endif // TIPOD_H
