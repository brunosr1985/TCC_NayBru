#ifndef CONECTABANCO_H
#define CONECTABANCO_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class conectabanco
{
private:

public:
    QSqlDatabase db;
    conectabanco();
    QSqlDatabase getDb() const;
    void setDb(const QSqlDatabase &value);
};

#endif // CONECTABANCO_H
