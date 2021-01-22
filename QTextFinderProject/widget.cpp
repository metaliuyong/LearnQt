#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <QTextCursor>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget){
    ui->setupUi(this);
    loadTextFile();
}

Widget::~Widget(){
    delete ui;
}


void Widget::on_findButton_clicked(){
    QString searchString = ui->lineEdit->text();
    if(searchString.isEmpty()){
        qDebug() << "Keyword can't be empty!";
        return;
    }
    ui->textEdit->find(searchString);
}

void Widget::loadTextFile(){
    QFile inputFile(":/files/input.txt");
    bool isInputFileOpen = inputFile.open(QIODevice::ReadOnly);
    if(isInputFileOpen == false){
        qDebug() << "Can't load the input file, please check it!";
        return;
    }
    QTextStream textStream(&inputFile);
    QString text = textStream.readAll();
    inputFile.close();

    ui->textEdit->setPlainText(text);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}
