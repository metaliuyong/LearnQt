#include "widget.h"
#include "ui_widget.h"
#include <QSqlRecord>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    DataBase::driverSupport();

    db.openDatabase();
    if(db.isTableExist("students") == false){
        db.createTable("students");
    }

    w2dba infoList[] = {
        {2020, "Twenty", 22},
        {2021, "Twenty One", 23},
        {2022, "Twenty Two", 24},
    };
    for(const w2dba &it : infoList){
        db.insertSingleData(it);
    }
    sqlTableModel = new QSqlTableModel(this);
    sqlTableModel->setTable("student");
    sqlTableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(sqlTableModel);

    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    sqlTableModel->select();
    connect(ui->confirmBtn, &QPushButton::clicked, this, &Widget::on_confirmBtn_clicked);
}

Widget::~Widget()
{
    db.closeDatabase();
    delete ui;
}


void Widget::on_printBtn_clicked(bool checked)
{
    db.queryTable("student");
}

void Widget::on_addBtn_clicked()
{
    QSqlRecord record = sqlTableModel->record();//获取空记录
    int row = sqlTableModel->rowCount();
    sqlTableModel->insertRecord(row, record);
}

void Widget::on_confirmBtn_clicked(){
    sqlTableModel->submitAll();
}

void Widget::on_cancelBtn_clicked(){
    sqlTableModel->revertAll();
    sqlTableModel->submitAll();
}

void Widget::on_deleteBtn_clicked(){
    QItemSelectionModel *selectedModel = ui->tableView->selectionModel();
    QModelIndexList list = selectedModel->selectedRows();
    for(const QModelIndex &x : list){
        sqlTableModel->removeRow(x.row());
    }
}

void Widget::on_searchBtn_clicked(){
    QString name = QString(ui->lineEdit->text());
    QString condition = QString("name = %1").arg(name);
    sqlTableModel->setFilter(condition);
    sqlTableModel->select();
}
