#include "widget.h"
#include <QApplication>
#include <QTranslator>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    //根据本地语言环境，选择语言
    QString locale = "../local/local_" + QLocale::system().name();
    translator.load(locale);
    a.installTranslator(&translator);

    Widget w;
    w.show();

    return a.exec();
}
