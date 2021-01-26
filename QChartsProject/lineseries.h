#ifndef LINESERIES_H
#define LINESERIES_H

#include <QLineSeries>
#include <QVector>
#include <QPointF>

QT_CHARTS_USE_NAMESPACE

class LineSeries : public QLineSeries
{
    Q_OBJECT
public:
    LineSeries();
//    LineSeries(QObject *parent = nullptr);
    void appendPoints(QVector<QPointF> points);

};

#endif // LINESERIES_H
