#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    label->move(100, 100);
    label->resize(200, 50);
    label->setText("I am a Label");

    label2->move(100, 200);
    label2->resize(200, 50);
    label2->setText("I am Label Two");

    //使鼠标不按下时也被追踪
    this->setMouseTracking(true);

    //启动计时器
    timerID = this->startTimer(1000);
    timerID2 = this->startTimer(500);

    button1->move(300, 300);
    button1->setText("Button 1");

    connect(button1, &QPushButton::clicked,
            []()
    {
        qDebug() << "Button 1 has been clicked";
    }
    );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event){
    int x = event->x();
    int y = event->y();
    if(event->button() == Qt::LeftButton){
        label->setText(QString("Move(%1, %2)").arg(x).arg(y));
        qDebug() << "mouseEvent called by Widget";
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event){
    int x = event->x();
    int y = event->y();
    //label->setText(QString("Move(%1, %2)").arg(x).arg(y));
}

void Widget::mouseReleaseEvent(QMouseEvent *event){
//    int x = event->x();
//    int y = event->y();
//    label->setText(QString("Move(%1, %2)").arg(x).arg(y));
//
}

void Widget::enterEvent(QEvent *event){
     label->setText(QString("Mouse has entered the window."));
}

void Widget::leaveEvent(QEvent *event){
     label->setText(QString("Mouse has left the window."));
}

void Widget::keyPressEvent(QKeyEvent *event){
     qDebug() << event->key();
     if(event->key() == Qt::Key_A){
         qDebug() << "I have pressed an \"A\" key";
     }
}

void Widget::timerEvent(QTimerEvent *event){
     if(event->timerId() == this->timerID){
         static int sec = 0;
         label->setText(QString("Timer(%1)").arg(sec++));
         if(sec == 5){
             this->killTimer(timerID);
         }
     }
     if(event->timerId() == this->timerID2){
         static int sec2 = 0;
           label2->setText(QString("Timer2(%1)").arg(sec2++));
     }
}

void Widget::closeEvent(QCloseEvent *event){
     int answer = QMessageBox::question(this, "Question", "Do you want to close the window");
     if(answer == QMessageBox::Yes){
         event->accept();
     }
     else{
         event->ignore();
     }
}

bool Widget::event(QEvent *event){
    if(event->type() == QEvent::Timer){
         //当event函数返回true时，事件停止传播
         return true;
    }
    else{
        return QWidget::event(event);
    }
}

