#include "newthread.h"

NewThread::NewThread(QObject *parent) : QObject(parent)
{
    isStop = false;
}


void NewThread::newThread(){
    while(isStop == false){
        QThread::sleep(1);
        emit mySignal();
        qDebug() << "NewThread线程号: " << QThread::currentThread();
    }
}


void NewThread::setFlag(bool flag){
    isStop = flag;
}
