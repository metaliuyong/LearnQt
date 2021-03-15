#include "mythread.h"
#include <QDebug>

MyThread::MyThread(QObject *parent) : QThread(parent)
{

}

void MyThread::run(){
    QThread::sleep(5);
    qDebug() << "I have been slept for 5 seconds";
    emit isDone();
}
