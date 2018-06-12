#ifndef DBHELPER_H
#define DBHELPER_H
#include <QSqlDatabase>

class DBHelper
{
private:
    QSqlDatabase db;
    static DBHelper*instance;
    DBHelper();
public:
    static DBHelper* getInstance();
    void createConn();
    void destoryConn();

};

#endif // DBHELPER_H
