#include "mybutoon.h"
#include <QPushButton>
#include <QDebug>

MyButoon::MyButoon(QWidget *parent) : QPushButton(parent)
{

}

void MyButoon::mousePressEvent(QMouseEvent * event)
{
    event->ignore();
    if(event->button() == Qt::LeftButton){
        qDebug() << "Left Mouse has been pressed";
    }
    else{
        QPushButton::mousePressEvent(event);
    }
}
