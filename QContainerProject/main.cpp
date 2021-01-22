//Qt的容器和STL的容器用法基本一致，除此之外可以用Java类型的迭代器
//Qt也有智能指针，对内存的管理要更加方便和严格

#include <QDebug>
#include <QVector>
#include <QtGlobal>
#include <QDateTime>
#include <QPointer>

int main(int argc, char **argv){

    //对于未使用的变量，可以通过Q_UNUSED()来设置使编译器不会报Warning
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    qDebug() << "***********************************************";

    qDebug() << "STL Iterator : " ;
    QVector<double> QVec {1.0, 2.0, 3.0, 4.0};
    for(QVector<double>::const_iterator it = QVec.cbegin(); it != QVec.end(); ++it){
        qDebug() << *it;
    }
    qDebug() << "***********************************************";


    qDebug() << "Java Iterator : ";
    QVectorIterator<double> javaIter(QVec);
    while(javaIter.hasNext()){
        qDebug() << javaIter.next();
    }
    qDebug() << "***********************************************";

    qDebug() << "C++ For Iterator : ";
    for(double x : QVec){
        qDebug() << x;
    }
    qDebug() << "***********************************************";

    //QPointer类似于C++标准中的智能指针
    QPointer<QObject> ipointer = new QObject();
    QPointer<QObject> jpointer = ipointer;
    qDebug() << "The memory address of ipointer is " << ipointer;
    qDebug() << "The memory address of ipointer is " << jpointer;
    qDebug() << "***********************************************";

    delete ipointer;
    qDebug() << "After delete the ipointer: ";
    qDebug() << "The memory address of ipointer is " << ipointer;
    qDebug() << "The memory address of ipointer is " << jpointer;
    if(jpointer == nullptr){
        qDebug("jpointer has been deleted too.");
    }

    qDebug() << "***********************************************";
}
