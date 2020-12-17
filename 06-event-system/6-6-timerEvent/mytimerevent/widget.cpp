#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    resize(500, 500);

    eventID = startTimer(50);
    curIndex = 0;
    timeoutFlag = false;
    hoverEnter = false;
    initPixmap();

    id1 = startTimer(1000*10);                  // 开启一个1秒定时器，返回其ID
    id2 = startTimer(1500);
    id3 = startTimer(2200);


    QTimer *timer = new QTimer(this);
    timer->start(1000*3);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateMap()));

}

Widget::~Widget()
{
    delete ui;
}

/**
 * @brief Widget::initPixmap 此函数用于读取图片，并将其存入数组中
 *
 * 使用计时器实现动图原理：
 * 动图即有序而连贯的打印一组图片，即按照一定时间间隔打印图片，则应该使用到计时器，
 * 在每个计时器函数中实现一次图片的打印，同时应该提前将图片编号。
 * 若图片数目较多，则应该编写读取图片的函数，若要实现循环，则应令设置一参数用于记录当前打印图片编号，当一轮结束后重置
 */
void Widget::initPixmap()
{
    for(int i=1;i<=128;i++)
    {
        //
        QString fileName = QString(":/res/res/loading%1.svg").arg(i+1,1,10,QLatin1Char('0'));
        QPixmap map(fileName);

        pixmap[i] = map;
    }
}

bool Widget::event(QEvent *event)
{
   if (event->type() == QEvent::HoverEnter)
   {
       qDebug() << "hoverEnter = " << hoverEnter;
       hoverEnter = true;
   }
   return QWidget::event(event);
}

void Widget::updateMap()
{
    qDebug() << "update()";
    timeoutFlag = true;

}

/**
 * @brief Widget::paintEvent 所有的绘图操作都应该在paintEvent
 * 当绘制不同的图形时，应该进行判断绘制。
 *
 * @param event
 */
void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    QRect q(0, 0, 322, 482);
    QRect q2(100, 100, 322, 482);
    painter.drawPixmap(q2,pixmap[curIndex],q);

    if (timeoutFlag == true && hoverEnter == true)
    {
        QRectF rect(210, 210, 187, 36);

        // 设置画笔
        QPen pen(Qt::red, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
        pen.setWidth(1);
        pen.setStyle(Qt::SolidLine);
        painter.setPen(pen);

        // 设置画刷
        QBrush brush(QColor(0, 0, 0), Qt::SolidPattern);
        painter.setBrush(brush);

        // 设置字体
        QFont font;
        font.setPixelSize(14);
        font.setWeight(400);
        painter.setFont(font);

        painter.drawText(rect, Qt::AlignLeft, tr("AlignLeft"));
        painter.drawRect(rect);

        /*
    painter.setPen(Qt::blue);
    painter.drawText(rect, Qt::AlignLeft, tr("AlignLeft"));
    */

    }

}


/**
 * @brief Widget::timerEvent 计时一次，curIndex变加1，对应图片的编号
 * @param event
 */
void Widget::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == id1) {       // 判断是哪个定时器
        //qDebug() << "timer1";
    }
    else if (event->timerId() == id2) {
        //qDebug() << "timer2";
    }
    else if (event->timerId() == eventID) {
        //qDebug() << "eventID: " << eventID << "curIndex = " << curIndex;
        curIndex++;
        if(curIndex >= 7) // 防止curIndex 超过图片的数量，7代表7张图片
        {
            curIndex = 0;
        }
        repaint(); // 重绘，每计时一次，变实现一次图片打印
    }
    else {
        //qDebug() << "timer3";
    }
}
