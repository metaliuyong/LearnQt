#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QChartView>

QT_CHARTS_USE_NAMESPACE

class ChartView : public QChartView{

public:
    ChartView();
    ChartView(QWidget *parent);
private:

protected:
    bool viewportEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

};

#endif // CHARTVIEW_H
