#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , interruptDlg(new InterruptDlg(this))
{
    //interruptDlg->setWindowFlag(Qt::FramelessWindowHint | Qt::Dialog);
    interruptDlg->setObjectName("中断界面");
    interruptDlg->exec();
}

Widget::~Widget()
{

}

