#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QImage>
#include <QPixmap>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    int eventID;
    int curIndex;

    void initPixmap();
    bool timeoutFlag;
    bool hoverEnter;
    bool event(QEvent *event);

private:
    Ui::Widget *ui;
    int id1, id2, id3;
    QPixmap pixmap[128];

protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);

private slots:
    void updateMap();


};

#endif // WIDGET_H
