#include "buttonwidget.h"

ButtonWidget::ButtonWidget(QWidget *parent) : QWidget(parent)
{
    //默认可以捕捉到鼠标
    setMouseTracking(true);
    setFixedSize(400,300);
    button = new QPushButton(this);
    button->setGeometry(100,100,200,100);
    button->setText("hello");
    button->setMouseTracking(true);
    w.setStartPos(70);
    w.setTriangleInfo(30, 30);
    w.setFixedSize(QSize(300, 150));
    w.setCenterWidget();
}
bool  ButtonWidget::enterBtn(QPoint p, QPushButton *btn)
{ int h = btn->height();
    int w = btn->width();
    QPoint btnMinPos = btn->pos();
    QPoint btnMaxPos = btn->pos();
    btnMaxPos.setX(btn->pos().x()+w);
    btnMaxPos.setY(btn->pos().y()+h);
    if(p.x() >= btnMinPos.x() && p.y() >= btnMinPos.y()&&
          p.x() <= btnMaxPos.x() && p.y() <= btnMaxPos.y())
       return true;
    else
       return false;
}
void  ButtonWidget::mouseMoveEvent(QMouseEvent *event)
{ if(enterBtn(event->pos(),button))
    {

         w.move(event->pos().x()-70,event->pos().y()+50);
         w.show();
   }
   else
       w.hide();

}
