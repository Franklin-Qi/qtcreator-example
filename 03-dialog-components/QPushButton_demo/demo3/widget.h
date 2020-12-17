#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    //设置小三角的起始位置
    void setStartPos(int startX);
    //设置小三角的宽和高
    void setTriangleInfo(int width,int height );
   //设置中间区域
    void setCenterWidget(QWidget* widget = nullptr);

protected:
    void paintEvent(QPaintEvent *event) ;

private:
    //小三角的起始位置
    int m_startx;
    //小三角的宽
    int m_triangleWidth;
    //小三角的高
    int m_triangleHeight;
};
#endif // WIDGET_H
