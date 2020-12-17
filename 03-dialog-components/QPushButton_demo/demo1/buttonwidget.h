#ifndef BUTTONWIDGET_H
#define BUTTONWIDGET_H

#include <QWidget>
#include "widget.h"
#include <QPushButton>
#include <QMouseEvent>
class ButtonWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ButtonWidget(QWidget *parent = nullptr);
    QPushButton *button;
    Widget w;
    bool enterBtn(QPoint,QPushButton *btn);
    void mouseMoveEvent(QMouseEvent *event) override;
signals:

public slots:
};

#endif // BUTTONWIDGET_H
