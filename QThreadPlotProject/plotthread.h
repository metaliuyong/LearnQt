#ifndef PLOTTHREAD_H
#define PLOTTHREAD_H

#include <QObject>
#include <QImage>

class PlotThread : public QObject
{
    Q_OBJECT
public:
    explicit PlotThread(QObject *parent = nullptr);
    void drawImag();

signals:
    emit void updateImage(QImage image);//signal可以将类的参数传递过去
};

#endif // PLOTTHREAD_H
