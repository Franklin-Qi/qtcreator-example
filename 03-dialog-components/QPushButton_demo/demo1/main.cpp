#include <QApplication>
#include "buttonwidget.h"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    ButtonWidget w;
    w.show();
    return a.exec();
}
