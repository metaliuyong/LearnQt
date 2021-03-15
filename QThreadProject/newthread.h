#ifndef NEWTHREAD_H
#define NEWTHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>

class NewThread : public QObject
{
    Q_OBJECT
public:
    explicit NewThread(QObject *parent = nullptr);

    void setFlag(bool flag = false);
    void newThread();
private:
    bool isStop;

signals:
    void mySignal();
};

#endif // NEWTHREAD_H
