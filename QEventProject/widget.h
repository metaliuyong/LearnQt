#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QEvent>
#include <QTimerEvent>
#include <QCloseEvent>
#include <QLabel>
#include <QPushButton>
#include "mybutoon.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    QLabel *label = new QLabel(this);
    QLabel *label2 = new QLabel(this);
    MyButoon *button1 = new MyButoon(this);
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    int timerID, timerID2;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *event);
    void closeEvent(QCloseEvent *event);
    bool event(QEvent *event);
};
#endif // WIDGET_H
