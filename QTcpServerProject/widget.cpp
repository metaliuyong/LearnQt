#include "widget.h"
#include "ui_widget.h"
#include <QString>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    tcpServer = new QTcpServer(this);
    tcpServer->listen(QHostAddress::Any, 33333);

    tcpSocket = nullptr;

    connect(tcpServer, &QTcpServer::newConnection, this, &Widget::onNewConnectionToServer);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onNewConnectionToServer(){
    tcpSocket = tcpServer->nextPendingConnection();
    connect(tcpSocket, &QTcpSocket::readyRead, this, &Widget::onReadyRead);
    QString ipClient = tcpSocket->peerAddress().toString();
    qint16 portClient = tcpSocket->peerPort();
    QString addressClient = QString("[%1:%2]:Connect Success.").arg(ipClient).arg(portClient);
    ui->textEditRead->setText(addressClient);
}

void Widget::onReadyRead(){
    QString text = tcpSocket->readAll();
    ui->textEditRead->append(text);
}

void Widget::on_pushButtonSend_clicked()
{
    if(tcpSocket == nullptr){
        qDebug() << "No Connection Yet.";
        return;
    }
    QString text = ui->textEditWrite->toPlainText();
    tcpSocket->write(text.toUtf8().data());
    ui->textEditWrite->clear();
}


void Widget::on_pushButtonDisconnect_clicked()
{
    if(tcpSocket == nullptr){
        qDebug() << "No Connection Yet.";
        return;
    }
    tcpSocket->disconnectFromHost();
    ui->textEditRead->append("Disconnect Success.");
    tcpSocket->close();
    tcpSocket = nullptr;
}
