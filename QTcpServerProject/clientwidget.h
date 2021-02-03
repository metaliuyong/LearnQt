#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class ClientWidget;
}

class ClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientWidget(QWidget *parent = nullptr);
    ~ClientWidget();

private slots:
    void on_pushButtonConnect_clicked();
    void onConnectToServer();
    void onReadyRead();
    void on_pushButtonSend_clicked();

    void on_pushButtonDisconnect_clicked();

private:
    Ui::ClientWidget *ui;
    QTcpSocket *tcpSocket;
};

#endif // CLIENTWIDGET_H
