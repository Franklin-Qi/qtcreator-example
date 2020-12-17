#include "ImageViewWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageViewWindow w;
    w.show();
    return a.exec();
}
