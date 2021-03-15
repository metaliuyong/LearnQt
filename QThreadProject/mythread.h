#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);

protected:
    //创建QThread的子类并重写实现run()虚函数
    //run()只能通过thread.start()间接调用，不可以直接调用

    void run() override;

signals:
    void isDone();
};

#endif // MYTHREAD_H
