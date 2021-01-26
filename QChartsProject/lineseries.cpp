#include "lineseries.h"

LineSeries::LineSeries(){

}

//LineSeries::LineSeries(QObject *parent) : QLineSeries(parent){

//}

void LineSeries::appendPoints(QVector<QPointF> points){
    for(QPointF point : points){
        append(point);
    }
}
