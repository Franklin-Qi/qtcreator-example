#ifndef CHANGE_H
#define CHANGE_H

#include <QWidget>
#include <QTranslator>
#include <QString>

#define QMPATH "../change/change_"

namespace Ui {
class change;
}

class change : public QWidget
{
    Q_OBJECT

public:
    explicit change(QWidget *parent = 0);
    ~change();

private slots:
    void on_comboBox_activated(const QString &arg1);

private:
    Ui::change *ui; 
    QTranslator *myTranslator;
    QString currentqmpath;
    void setAllText();
};

#endif // CHANGE_H
