#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "interruptdlg.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    InterruptDlg *interruptDlg;
};
#endif // WIDGET_H
