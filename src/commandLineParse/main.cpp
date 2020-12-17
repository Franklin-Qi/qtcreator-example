#include "MainWindow.h"

#include <QApplication>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setApplicationVersion("1.0.0.0");
    app.setApplicationName("xxxx tools");

    /* QCommandLineParser是提供了一系列命令行参数的类*/

    QCommandLineParser parser;

    //添加help选项(在窗口上有-h,--help and ?)，这个选项是由
    //QCommandLineParser自动自动处理的

    parser.addHelpOption();

    //添加 -v/--version选项，这个用来显示应用程序的版本信息
    //这个同样是由QCommandLineParser自动处理，同样可以通过
    //QCoreApplication::setApplicationVersion()来添加版本信息
    parser.addVersionOption();



    //通过QCommandLineOption类定义可能的命令行选项
    QCommandLineOption p(QStringList() << "p" << "package", "set package name of Android", "com.itcast.hello");
    parser.addOption(p);

    QCommandLineOption l(QStringList() << "l" << "language", "set code language c++ or lua", "c++");
    parser.addOption(l);


    //通过app.arguments()返回一系列的命令行参数
    //parser.parse(app.arguments());
    parser.process(app);



    //通过parser来解析一系列命令行参数
    QString strValue = parser.value("p");
    //qCritical() << "p is" << strValue;

    //打印出解析出来的命令行参数
    printf("p is %s\n",strValue.toUtf8().data());

    //表示的是language
    strValue = parser.value("l");

    qDebug() << parser.positionalArguments();


    MainWindow w;
    w.show();
    return app.exec();
}
