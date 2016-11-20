#include "conectabanco.h"

QSqlDatabase conectabanco::getDb() const
{
    return db;
}

void conectabanco::setDb(const QSqlDatabase &value)
{
    db = value;
}

conectabanco::conectabanco()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","conn");
    db.setHostName("tccnaybru.cgqgmlbbcd8e.us-west-2.rds.amazonaws.com");
    db.setDatabaseName("tccnaybru");
    db.setPassword("bu381025");
    db.setUserName("brunosr");
    db.setPort(5432);
    db.open();

}
