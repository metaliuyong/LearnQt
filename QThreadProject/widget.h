#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLCDNumber>
#include <QTimer>
#include "mythread.h"
#include "newthread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QPushButton *button0, *button1, *button2;
    QLCDNumber *lcd0, *lcd1;
    QTimer *timer;
    QThread *thread;
    MyThread *mythread;
    NewThread *newthread;
    void dealDone();
    void dealSignal();
    void dealSignal2();

private:
    Ui::Widget *ui;

signals:
    void startSignal();
};
#endif // WIDGET_H
