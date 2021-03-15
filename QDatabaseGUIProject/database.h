#ifndef DATABASE_H
#define DATABASE_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

using w2dba = struct{
    int id;
    QString name;
    int age;
};

class DataBase
{
public:
    DataBase();
    static void driverSupport();
    bool openDatabase();
    void createTable(const QString &tableName);
    bool isTableExist(const QString &tableName);
    void queryTable(const QString &tableName);
    void insertSingleData(const w2dba &singleData);
    void closeDatabase();
private:
    QSqlDatabase database;
};

#endif // DATABASE_H
