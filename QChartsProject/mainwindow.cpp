#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QLineSeries *lineSeries = new LineSeries();
//    QVector<QPointF> points {QPointF(1, 2), QPointF(3, 4), QPointF(5, 6)};
//    for(QPointF point : points){
//        lineSeries->append(point);
//    }

//    QChart *chart = new QChart();
//    chart->legend()->hide();
//    chart->addSeries(lineSeries);
//    chart->setTitle("QCharts Examples");

//    QChartView *chartView = new QChartView();
//    chartView->setChart(chart);

//    setCentralWidget(chartView);

    LineSeries *lineSeries = new LineSeries();
//    QVector<QPointF> points {QPointF(1, 2), QPointF(3, 4), QPointF(5, 6)};
//    lineSeries->appendPoints(points);

    QVector<QPointF> points {QPointF(1, 2), QPointF(3, 4), QPointF(5, 6)};
    for(QPointF point : points){
        lineSeries->append(point);
    }


    Chart *chart = new Chart();
    chart->legend()->hide();
    chart->addSeries(lineSeries);
//    chart->createDefaultAxes();
    chart->setTitle("Chart Example");

    ChartView *chartView = new ChartView();
    chartView->setChart(chart);


    setCentralWidget(chartView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

