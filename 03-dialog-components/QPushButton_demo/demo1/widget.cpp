#include "widget.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include <QLabel>
#define SHADOW_WIDTH  15     //小三角的阴影宽度
#define TRIANGLE_WIDTH 15    //小三角的宽度
#define TRIANGLE_HEIGHT 15    //小三角的高度
#define BORDER_RADIUS 15      //窗口边角弧度

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , m_startx(5)
    , m_triangleWidth(TRIANGLE_WIDTH)
    , m_triangleHeight(TRIANGLE_HEIGHT)
{
    //隐藏窗体边框
    setWindowFlag(Qt::FramelessWindowHint);
    //窗体透明
    setAttribute(Qt::WA_TranslucentBackground);
    //设置阴影边框
    auto shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setOffset(0,0);
    shadowEffect->setColor(Qt::gray);
    shadowEffect->setBlurRadius(BORDER_RADIUS);
    this->setGraphicsEffect(shadowEffect);
    setFixedSize(150,200);
}

void Widget::setCenterWidget(QWidget *widget)
{
    QHBoxLayout* hMainLayout = new  QHBoxLayout(this);
    QLabel *textLabel = new QLabel;
    textLabel->setAlignment(Qt::AlignCenter);
    textLabel->setText("This is ArrowWidget");
    hMainLayout->addWidget(textLabel);
    hMainLayout->setSpacing(0);
    //int left, int top, int right, int bottom
    hMainLayout->setContentsMargins(SHADOW_WIDTH,SHADOW_WIDTH + TRIANGLE_WIDTH, SHADOW_WIDTH , SHADOW_WIDTH);
}
void Widget::setStartPos(int startX)
{
    m_startx = startX;
}

void Widget::setTriangleInfo(int width, int height)
{
    m_triangleWidth = width;
    m_triangleHeight = height;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(255,255,255));
    //小三角
    QPolygon trianglePolygon;
    trianglePolygon << QPoint(m_startx, m_triangleWidth + SHADOW_WIDTH);
    trianglePolygon << QPoint(m_startx+m_triangleWidth/2,SHADOW_WIDTH);
    trianglePolygon << QPoint(m_startx + m_triangleWidth,m_triangleHeight + SHADOW_WIDTH);
    QPainterPath drawPath;
    //圆角矩形
    drawPath.addRoundRect(QRect(SHADOW_WIDTH , m_triangleHeight + SHADOW_WIDTH ,
                                width()-SHADOW_WIDTH *2 ,height() -SHADOW_WIDTH *2 -m_triangleHeight),
                         BORDER_RADIUS,BORDER_RADIUS);
    drawPath.addPolygon(trianglePolygon);
    painter.drawPath(drawPath);
    Q_UNUSED(event);

}
Widget::~Widget()
{

}

