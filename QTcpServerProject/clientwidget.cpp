#include "clientwidget.h"
#include "ui_clientwidget.h"
#include <QString>
#include <QHostAddress>

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);

    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket, &QTcpSocket::connected, this, &ClientWidget::onConnectToServer);
    connect(tcpSocket, &QTcpSocket::readyRead, this, &ClientWidget::onReadyRead);
}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_pushButtonConnect_clicked()
{
    QString ipServer = ui->lineEditIp->text();
    qint16 portServer = ui->lineEditPort->text().toInt();
    if(ipServer == "" || portServer == 0){
        qDebug() << "Please complete the server ip and port.";
        return;
    }
    tcpSocket->connectToHost(QHostAddress(ipServer), portServer);
}

void ClientWidget::onReadyRead(){
    QString text = tcpSocket->readAll();
    ui->textEditRead->append(text);
}

void ClientWidget::onConnectToServer(){
    ui->textEditRead->setText("Connect Success.");
}

void ClientWidget::on_pushButtonSend_clicked()
{
    QString text = ui->textEditWrite->toPlainText();
    tcpSocket->write(text.toUtf8().data());
    ui->textEditWrite->clear();
}

void ClientWidget::on_pushButtonDisconnect_clicked()
{
    if(tcpSocket == nullptr){
        qDebug() << "No Connection Yet";
    }
    tcpSocket->disconnectFromHost();
    ui->textEditRead->append("Disconnect success.");
}
