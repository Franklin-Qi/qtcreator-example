#include "change.h"
#include "ui_change.h"

#define EN      0
#define zh_CN   1
#define JA      2

change::change(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::change)
{
    ui->setupUi(this);

    ui->comboBox->addItem(tr("English"));
    ui->comboBox->addItem(tr("Chinese"));
    ui->comboBox->addItem(tr("Japanese"));

   //根据当前系统的语言环境，选择条目
   QString qm = QLocale::system().name();
   if (qm == "en")
       ui->comboBox->setCurrentIndex(0);
   else if (qm == "zh_CN")
       ui->comboBox->setCurrentIndex(1);
   else if (qm == "ja")
       ui->comboBox->setCurrentIndex(2);

   QString qmpath = QMPATH;
   currentqmpath = qmpath + qm; // 当前翻译文件的路径

   myTranslator = new QTranslator;
   myTranslator->load(QString(currentqmpath));
   qApp->installTranslator(myTranslator); //安装翻译器

   setAllText();
}

change::~change()
{
    delete ui;
}

void change::on_comboBox_activated(const QString &arg1)
{
    QString qmpath = QMPATH;

    int index = ui->comboBox->currentIndex();

    switch(index) {
    case EN:
      qmpath += "en";
      break;
    case zh_CN:
      qmpath += "zh_CN";
      break;
    case JA:
      qmpath += "ja";
      break;
    default :
      qmpath += "zh_CN";
      break;
    }

    if(currentqmpath != qmpath)
    {  
        myTranslator->load(QString(qmpath));
        currentqmpath = qmpath;
    }

    setAllText();
}

void change::setAllText()
{
    setWindowTitle(tr("change"));
    ui->label->setText(tr("hello"));
    ui->comboBox->setItemText(0, tr("English"));
    ui->comboBox->setItemText(1, tr("Chinese"));
    ui->comboBox->setItemText(2, tr("Japanese"));
}

