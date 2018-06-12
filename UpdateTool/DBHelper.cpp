#include "DBHelper.h"


DBHelper*DBHelper::instance = 0;

DBHelper*DBHelper::getInstance()
{
    if(0 == instance)
    {
        instance = new DBHelper();
    }
    return instance;
}
DBHelper::DBHelper()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}

void DBHelper::createConn()
{
    db.setDatabaseName("C:\\sqlite\\test.db");
    db.open();
}
void DBHelper::destoryConn()
{
    db.close();
    db.removeDatabase("C:\\sqlite\\test.db");
}
