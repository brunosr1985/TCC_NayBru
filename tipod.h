#ifndef TIPOD_H
#define TIPOD_H


class tipod
{
private:
    int id;
    string tipo;
    float SLA;

public:

    tipod();
    int getId() const;
    void setId(int value);
    string getTipo() const;
    void setTipo(const string &value);
    float getSLA() const;
    void setSLA(float value);
};

#endif // TIPOD_H
