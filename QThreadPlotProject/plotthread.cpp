#include "plotthread.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QRandomGenerator>

PlotThread::PlotThread(QObject *parent) : QObject(parent)
{

}

void PlotThread::drawImag(){
    QImage image(500, 500, QImage::Format_RGB32);
    QPainter painter(&image);

    QPen pen;
    pen.setWidth(5);
    painter.setPen(pen);

//    QBrush brush;
//    brush.setColor(Qt::darkBlue);
//    brush.setStyle(Qt::Dense6Pattern);
//    painter.setBrush(brush);

    QPoint point[5] = {
        QPoint(QRandomGenerator::global()->bounded(0, 200), QRandomGenerator::global()->bounded(0, 200)),
        QPoint(QRandomGenerator::global()->bounded(0, 200), QRandomGenerator::global()->bounded(0, 200)),
        QPoint(QRandomGenerator::global()->bounded(0, 200), QRandomGenerator::global()->bounded(0, 200)),
        QPoint(QRandomGenerator::global()->bounded(0, 200), QRandomGenerator::global()->bounded(0, 200)),
        QPoint(QRandomGenerator::global()->bounded(0, 200), QRandomGenerator::global()->bounded(0, 200)),
    };

    painter.drawPolygon(point, 5);
    emit updateImage(image);
}
