#include "widget.h"
#include "ui_widget.h"
#include <QDir>
#include <QDebug>
#include <QFileDialog>
#include <QInputDialog>
#include <QStringList>
#include <QFont>
#include <QLocale>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QLabel *labelFileDialog = new QLabel(this);
    labelFileDialog->move(50, 30);
    labelFileDialog->setText("文件对话框:");

    QPushButton *btnOpenSignleFile = new QPushButton(this);
    btnOpenSignleFile->move(50, 50);
    btnOpenSignleFile->setText("打开单个文件");

    QPushButton *btnOpenMultipleFiles = new QPushButton(this);
    btnOpenMultipleFiles->move(250, 50);
    btnOpenMultipleFiles->setText("打开多个文件");

    QPushButton *btnOpenDirectory = new QPushButton(this);
    btnOpenDirectory->move(450, 50);
    btnOpenDirectory->setText("打开已有目录");

    QPushButton *btnSaveFile = new QPushButton(this);
    btnSaveFile->move(650, 50);
    btnSaveFile->setText("保存文件");

    plainTextEdit = new QPlainTextEdit(this);
    plainTextEdit->move(50, 350);
    plainTextEdit->resize(600, 200);

    connect(btnOpenSignleFile, &QPushButton::pressed, this, &Widget::onPressBtnOpenSingleFile);
    connect(btnOpenMultipleFiles, &QPushButton::pressed, this, &Widget::onPressBtnOpenMutipleFiles);
    connect(btnOpenDirectory, &QPushButton::pressed, this, &Widget::onPressBtnOpenDirectory);
    connect(btnSaveFile, &QPushButton::pressed, this, &Widget::onPressBtnSaveFile);

    QLabel *labelInputDialog = new QLabel(this);
    labelInputDialog->move(50, 130);
    labelInputDialog->setText("标准输入对话框:");

    QPushButton *btnInputString = new QPushButton(this);
    btnInputString->move(50, 150);
    btnInputString->setText("输入字符串");

    QPushButton *btnInputInteger = new QPushButton(this);
    btnInputInteger->move(250, 150);
    btnInputInteger->setText("输入整数");

    QPushButton *btnInputFloat = new QPushButton(this);
    btnInputFloat->move(450, 150);
    btnInputFloat->setText("输入浮点数");

    QPushButton *btnInputItem = new QPushButton(this);
    btnInputItem->move(650, 150);
    btnInputItem->setText("条目选择输入");

    connect(btnInputString, &QPushButton::pressed, this, &Widget::onPressBtnInputString);
    connect(btnInputInteger, &QPushButton::pressed, this, &Widget::onPressBtnInputInteger);
    connect(btnInputFloat, &QPushButton::pressed, this, &Widget::onPressBtnInputFloat);
    connect(btnInputItem, &QPushButton::pressed, this, &Widget::onPressBtnInputItem);


    QLabel *labelMessageDialog = new QLabel(this);
    labelMessageDialog->move(50, 230);
    labelMessageDialog->setText("消息对话框:");

    QPushButton *btnQuestionDialog = new QPushButton(this);
    btnQuestionDialog->move(50, 250);
    btnQuestionDialog->setText("问题对话框");

    QPushButton *btnInformationDialog = new QPushButton(this);
    btnInformationDialog->move(250, 250);
    btnInformationDialog->setText("信息对话框");

    QPushButton *btnWarningDialog = new QPushButton(this);
    btnWarningDialog->move(450, 250);
    btnWarningDialog->setText("警告对话框");

    QPushButton *btnCriticalDialog = new QPushButton(this);
    btnCriticalDialog->move(650, 250);
    btnCriticalDialog->setText("错误对话框");

    QPushButton *btnAboutDialog = new QPushButton(this);
    btnAboutDialog->move(50, 280);
    btnAboutDialog->setText("关于对话框");

    QPushButton *btnAboutQtDialog = new QPushButton(this);
    btnAboutQtDialog->move(250, 280);
    btnAboutQtDialog->setText("关于Qt对话框");

    connect(btnQuestionDialog, &QPushButton::clicked, this, &Widget::onClickBtnQuestion);
    connect(btnInformationDialog, &QPushButton::clicked, this, &Widget::onClickBtnInformation);
    connect(btnWarningDialog, &QPushButton::clicked, this, &Widget::onClickBtnWarning);
    connect(btnCriticalDialog, &QPushButton::clicked, this, &Widget::onClickBtnCritical);
    connect(btnAboutDialog, &QPushButton::clicked, this, &Widget::onClickBtnAbout);
    connect(btnAboutQtDialog, &QPushButton::clicked, this, &Widget::onClickBtnAboutQt);

    QPushButton *btnClearText = new QPushButton(this);
    btnClearText->move(50, 320);
    btnClearText->setText("清除文本框内容");

    connect(btnClearText, &QPushButton::clicked, this, &Widget::onClickBtnClearText);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onPressBtnOpenSingleFile(){
    QString currentPath = QDir::currentPath();
    QString dialogTitle = "请选择一个文件";
    QString filter =  "文本文件(*.txt);图片文件(*.jpg *.png);所有文件(*.*)";
    QString openFileName = QFileDialog::getOpenFileName(this, dialogTitle, currentPath, filter);
    plainTextEdit->appendPlainText(openFileName);
}


void Widget::onPressBtnOpenMutipleFiles(){
    QString currentPath = QDir::currentPath();
    QString dialogTitle = "请选择多个文件";
    QString filter =  "文本文件(*.txt);图片文件(*.jpg *.png);所有文件(*.*)";
    QStringList openFileNames = QFileDialog::getOpenFileNames(this, dialogTitle, currentPath, filter);
    for(const QString &str : openFileNames){
        plainTextEdit->appendPlainText(str);
    }
}

void Widget::onPressBtnOpenDirectory(){
    QString currentPath = QDir::currentPath();
    QString dialogTitle = "请选择一个目录";
    QString dirName = QFileDialog::getExistingDirectory(this, dialogTitle, currentPath, QFileDialog::ShowDirsOnly);
    plainTextEdit->appendPlainText(dirName);
}

void Widget::onPressBtnSaveFile(){
    QString currentPath = QDir::currentPath();
    QString dialogTitle = "请选择你要保存的路径或文件";
    QString filter =  "文本文件(*.txt);图片文件(*.jpg *.png);所有文件(*.*)";
    //QDialog::getSaveFileName并不会真的就创建一个文件，而是返回你需要创建文件的目录信息，而具体的写操作需要另外写代码来实现
    QString dirName = QFileDialog::getSaveFileName(this, dialogTitle, currentPath, filter);
    plainTextEdit->appendPlainText(dirName);
}

void Widget::onPressBtnInputString(){
    QString dialogTitle = "输入字符串";
    QString textLable = "请输入字符串: ";
    //defaultInput是一个缺省值参数，也就是初始输入就是这个.
    QString defaultInput = "新建文本.txt";
    QLineEdit::EchoMode echoMode = QLineEdit::Normal;
    QString inputString = QInputDialog::getText(this, dialogTitle, textLable, echoMode, defaultInput);
    plainTextEdit->appendPlainText(inputString);
}

void Widget::onPressBtnInputInteger(){
    QString dialogTitle = "输入整数";
    QString textLable = "请输入整数: ";
    int minValue = 0;
    int maxValue = 10000;
    int defaultValue = plainTextEdit->font().pointSize();
    int stepValue = 1;

    //bool值ok用来返回对话框选择的Yes和No，来选择执行后面的操作.
    bool ok = false;
    int inputInt = QInputDialog::getInt(this, dialogTitle, textLable, defaultValue, minValue, maxValue, stepValue, &ok);
    if(ok){
        QFont font = plainTextEdit->font();
        font.setPointSize(inputInt);
        plainTextEdit->appendPlainText(QString::number(inputInt));
        plainTextEdit->setFont(font);
    }
}

void Widget::onPressBtnInputFloat(){
    QString dialogTitle = "输入浮点数";
    QString textLable = "请输入浮点数: ";
    double minValue = 0;
    double maxValue = 10000;
    double defaultValue = 8888.88;

    //decimals用来设置小数点后面的位数
    int decimals = 2;

    //bool值ok用来返回对话框选择的Yes和No，来选择执行后面的操作.
    bool ok = false;

    double inputDouble = QInputDialog::getDouble(this, dialogTitle, textLable, defaultValue, minValue, maxValue, decimals, &ok);
    if(ok){
        plainTextEdit->appendPlainText(QString::number(inputDouble));
    }
}

void Widget::onPressBtnInputItem(){
    QString dialogTitle = "条目选择";
    QString textLable = "请选择条目: ";

    QStringList items;
    items << "优秀" << "良好" << "合格" << "不合格";

    //editable用来设置条目选择是否可以自定义编辑，如果是false，那么结果只能从items里面选择
    bool editable = false;
    int currentIndex = 0;

    //bool值ok用来返回对话框选择的Yes和No，来选择执行后面的操作.
    bool ok = false;

    QString inputItem = QInputDialog::getItem(this, dialogTitle, textLable, items, currentIndex, editable, &ok);
    if(ok){
        plainTextEdit->appendPlainText(inputItem);
    }
}



void Widget::onClickBtnQuestion(){
    QString dialogTitle = "问题对话框";
    QString text = "这是一个问题对话框，是否关闭";
    QMessageBox::StandardButton result = QMessageBox::question(this, dialogTitle, text, QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, QMessageBox::NoButton);
    if(result == QMessageBox::Yes){
        plainTextEdit->appendPlainText("QMessageBox::Yes");
    }else if(result == QMessageBox::No){
        plainTextEdit->appendPlainText("QMessageBox::No");
    }else if(result == QMessageBox::Cancel){
        plainTextEdit->appendPlainText("QMessageBox::Cancel");
    }else{
        plainTextEdit->appendPlainText("QMessageBox::无选择");
    }
}

void Widget::onClickBtnInformation(){
    QString dialogTitle = "消息对话框";
    QString text = "这是一个消息对话框";
    QMessageBox::information(this, dialogTitle, text, QMessageBox::NoButton);
}

void Widget::onClickBtnWarning(){
    QString dialogTitle = "警告对话框";
    QString text = "这是一个警告对话框";
    QMessageBox::warning(this, dialogTitle, text, QMessageBox::Yes);
}

void Widget::onClickBtnCritical(){
    QString dialogTitle = "错误对话框";
    QString text = "这是一个错误对话框";
    QMessageBox::critical(this, dialogTitle, text);
}

void Widget::onClickBtnAbout(){
    QString dialogTitle = "关于对话框";
    QString text = "这是一个关于对话框";
    QMessageBox::about(this, dialogTitle, text);
}

void Widget::onClickBtnAboutQt(){
    QString dialogTitle = "关于Qt对话框";
    QMessageBox::aboutQt(this, dialogTitle);
}

void Widget::onClickBtnClearText(){
    plainTextEdit->clear();
}
