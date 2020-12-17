#include "widget.h"
#include <QApplication>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Widget w;
    w.setStartPos(70);
    w.setTriangleInfo(30, 30);
    w.setFixedSize(QSize(300, 150));
    w.setCenterWidget();
    w.show();
    return a.exec();
}
