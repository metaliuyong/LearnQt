#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include "database.h"

//Qt操作数据库只不过是把在Command Line输入的指令通过Qt类的API接口传给后台数据库而已，
//所谓的增删改查语句也是不变的，只要知道怎么用String下达SqlQuery语句就可以了。
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    DataBase db;
    db.driverSupport();
    db.openDatabase();
    db.createTable();
    qDebug() << db.isTableExist("student");
    w2dba infoList[] = {
        {2020, "Twenty", 22},
        {2021, "Twenty One", 23},
        {2022, "Twenty Two", 24},
    };
    for(const w2dba &it : infoList){
        db.insertSingleData(it);
    }
    db.queryTable("student");
}

Widget::~Widget()
{
    delete ui;
}

