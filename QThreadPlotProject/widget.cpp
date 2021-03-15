#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    btn1 = new QPushButton(this);
    btn1->setText("重绘图片");
    btn1->move(250, 0);

    plotThread = new PlotThread;
    thread = new QThread(this);
    plotThread->moveToThread(thread);
    thread->start();

    connect(btn1, &QPushButton::clicked, plotThread, &PlotThread::drawImag);
    connect(plotThread, &PlotThread::updateImage, this, &Widget::getImage);
    connect(this, &Widget::destroyed, this, &Widget::dealClose);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawImage(50, 50, this->image);
}

void Widget::getImage(QImage tempImage){
    this->image = tempImage;
    update();//间接调用paintEvent
}

void Widget::dealClose(){
    thread->quit();
    thread->wait();
    delete plotThread;
}

