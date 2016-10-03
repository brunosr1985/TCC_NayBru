#ifndef GRUPOP_H
#define GRUPOP_H


class GrupoP
{
private:
    int id;
    QString nome;
public:
    GrupoP();
    int getId() const;
    void setId(int value);
    QString getNome() const;
    void setNome(const QString &value);
};

#endif // GRUPOP_H
