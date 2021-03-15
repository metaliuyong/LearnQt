#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlTableModel>
#include "database.h"
#include <QString>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_printBtn_clicked(bool checked);
    void on_confirmBtn_clicked();
    void on_addBtn_clicked();
    void on_cancelBtn_clicked();
    void on_deleteBtn_clicked();
    void on_searchBtn_clicked();

private:
    Ui::Widget *ui;
    QSqlTableModel *sqlTableModel;
    DataBase db;

};
#endif // WIDGET_H
