#include "change.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    change w;
    w.show();

    return a.exec();
}
