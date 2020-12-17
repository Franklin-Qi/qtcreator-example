#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QDesktopWidget>
#include <QRectF>
#include <QString>
#include <QLineEdit>
#include <QDebug>
#include <QDir>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    /*
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
                                                    */
/*
    QFileDialog *filedialog=new QFileDialog(this);
    filedialog->setAcceptMode(QFileDialog::AcceptOpen);
    filedialog->setViewMode(QFileDialog::Detail);
    filedialog->setFileMode(QFileDialog::Directory);//只显示目录
    filedialog->setDirectory("/home");
    filedialog->setOptions(QFileDialog::ShowDirsOnly
                           | QFileDialog::DontResolveSymlinks
                           | QFileDialog::DontUseNativeDialog);

    filedialog->setWindowTitle(tr("Outputdirectory"));
    filedialog->setLabelText(QFileDialog::Reject,tr("Cancel"));

    //设置窗口大小
    QDesktopWidget *desktopWidget=QApplication::desktop();
    QRect rect= desktopWidget->screenGeometry();
    filedialog->resize(rect.width()*0.8,rect.height()*0.8);
    */

    QString filter="*.jpg;;*.png;;*.pdf;;*.bmp"; //文件过滤器
    QLineEdit *textName = new  QLineEdit();
    textName->setText("scanner01");
    QString curPath;
    if(curPath.isEmpty())
        curPath=QDir::homePath() ; //获取家目录的路径
    //保存文件
    QString dlgTitle=tr("Save as ..."); //对话框标题
    //QString filter="文本文件(*.txt);;h文件(*.h);;C++文件(.cpp);;所有文件(*.*)"; //文件过滤器
    QString pathName = curPath + "/" + textName->text();
    QString aFileName=QFileDialog::getSaveFileName(this,dlgTitle,pathName,filter);
    if (!aFileName.isEmpty())
        qDebug() << "Not Empty";


}
