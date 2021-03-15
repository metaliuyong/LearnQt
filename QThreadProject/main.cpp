#include "widget.h"

#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    //设置应用程序的全局解码方式为Unicode
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
