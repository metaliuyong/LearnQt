#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QThread>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    button0 = new QPushButton();
    button0->setParent(this);
    button0->move(250, 400);
    button0->setText("Start");
    connect(button0, &QPushButton::clicked,
            [this]()
            {
        if(this->timer->isActive() == false){
            timer->start(500);
        }
        mythread->start();

//        QThread::sleep(5);
//        timer->stop();
//        qDebug() << "over";
    }
    );

    button1 = new QPushButton();
    button1->setParent(this);
    button1->move(350, 400);
    button1->setText("Start New");
    connect(button1, &QPushButton::clicked,
            [this]()
            {
        //按下Start New按钮，启动线程thread,但是并没有启动加入到其中的线程newthread.
        thread->start();

        //如果直接调用，那么newthread线程函数仍然是在主线程中执行的.
        //newthread->newThread();

        //应该通过signal-slot机制来调用
        emit startSignal();
    }
    );

    //按下按钮Start New会启动thread并发射一个信号给newthread的槽函数
    //newthread槽函数会发射信号给Widget的dealSignal槽函数使LCD开始计数.

    button2 = new QPushButton();
    button2->setParent(this);
    button2->move(450, 400);
    button2->setText("Stop");
    connect(button2, &QPushButton::clicked,
            [this]()
    {
        thread->quit();
    }
    );

    lcd0 = new QLCDNumber();
    lcd0->setParent(this);
    lcd0->move(200, 100);
    lcd0->display(0);

    lcd1 = new QLCDNumber();
    lcd1->setParent(this);
    lcd1->move(400, 100);
    lcd1->display(0);

    timer = new QTimer();
    timer->setParent(this);
    connect(timer, &QTimer::timeout,
            [this](){
        static int i = 0;
        lcd0->display(i++);
    }
    );

    mythread = new MyThread(this);
    connect(mythread, &MyThread::isDone, this, &Widget::dealDone);

    thread = new QThread(this);

    //新的线程分配不能指定父对象,其父对象应该是要移动到的子线程，如果事先指定会占据父对象
    newthread = new NewThread();

    newthread->moveToThread(thread);

    connect(this, &Widget::startSignal, newthread, &NewThread::newThread);

    connect(newthread, &NewThread::mySignal, this, &Widget::dealSignal);
    connect(newthread, &NewThread::mySignal, this, &Widget::dealSignal2);
    qDebug() << "主线程号为: " << QThread::currentThread();
}

void Widget::dealDone(){
    this->timer->stop();
    this->mythread->quit();
    qDebug() << "Timer has been killed.";
}

void Widget::dealSignal(){
    static int i = 0;
    this->lcd1->display(i++);
    qDebug() << "I have deal the newthread signal.";
}

void Widget::dealSignal2(){
    qDebug() << "The signal has been deal by Slot2";
}

Widget::~Widget()
{
    delete ui;
}

