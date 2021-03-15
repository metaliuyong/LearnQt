#ifndef MYBUTOON_H
#define MYBUTOON_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>

class MyButoon : public QPushButton
{
    Q_OBJECT
public:
    explicit MyButoon(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent * event);

signals:

};

#endif // MYBUTOON_H
