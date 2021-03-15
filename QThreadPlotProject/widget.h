#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>
#include <QPaintEvent>
#include <QThread>
#include <QPushButton>
#include "plotthread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QImage image;
    PlotThread *plotThread;
    QThread *thread;
    void dealClose();
    void getImage(QImage tempImage);

protected:
    void paintEvent(QPaintEvent *event);
private:
    Ui::Widget *ui;
    QPushButton *btn1;
};
#endif // WIDGET_H
