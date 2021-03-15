#include "database.h"
#include <QDebug>

DataBase::DataBase()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("demo.db");
}

void DataBase::driverSupport(){
    qDebug() << QSqlDatabase::drivers();
}

bool DataBase::openDatabase(){
    bool isOpenDatabase = database.open();
    if(isOpenDatabase == false){
        qDebug() << "Can't open database";
        return false;
    }
    return true;
}
void DataBase::createTable(){
    QSqlQuery sqlQuery;
    QString createSql = "Create Table student(\
                                id INT PRIMARY KEY NOT NULL,\
                                name TEXT NOT NULL,\
                                age INT NOT NULL)";
    sqlQuery.prepare(createSql);
    if(sqlQuery.exec() == false){
        qDebug() << "Fail to create a table";
    }else{
        qDebug() << "Table has been created";
    }
}
bool DataBase::isTableExist(const QString &tableName){
    return this->database.tables().contains(tableName);
}
void DataBase::queryTable(const QString &tableName){
    QSqlQuery sqlQuery;
    QString queryTable = "SELECT * FROM " + tableName;
    sqlQuery.prepare(queryTable);
    if(sqlQuery.exec() == false){
        qDebug() << "Fail to query Table " + tableName;
        return;
    }
    qDebug() << "id \t name \t age";
    while(sqlQuery.next()){
        int id = sqlQuery.value(0).toInt();
        QString name = sqlQuery.value(1).toString();
        int age = sqlQuery.value(2).toInt();
        qDebug() << QString("%1  %2  %3").arg(id).arg(name).arg(age);
    }
}

void DataBase::insertSingleData(const w2dba &singleData){
    QSqlQuery sqlQuery;
    QString insertSingle = "INSERT INTO student VALUES(:id, :name, :age)";
    sqlQuery.prepare(insertSingle);
    sqlQuery.bindValue(":id", singleData.id);
    sqlQuery.bindValue(":name", singleData.name);
    sqlQuery.bindValue(":age", singleData.age);
    if(sqlQuery.exec() == false){
        qDebug() << "Fail to insert single data to Table student";
    }
}

void DataBase::closeDatabase(){
    database.close();
}
