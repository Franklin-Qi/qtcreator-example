#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //设置窗体边框隐藏
    setWindowFlag(Qt::FramelessWindowHint);
    //设置窗体透明
    setAttribute(Qt::WA_TranslucentBackground);
}

void  Widget::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    QColor color = QColor(Qt::gray);
    color.setAlpha(180);
    painter.setBrush(color);
    //设置点集
    static const QPointF point[7]=
    {
        QPointF(30,2),
        QPointF(20,10),
        QPointF(10,10),
        QPointF(10,90),
        QPointF(100,90),
        QPointF(100,10),
        QPointF(33,10)
    };
    //绘制多边形
    painter.drawPolygon(point,7);
}
Widget::~Widget()
{
}

