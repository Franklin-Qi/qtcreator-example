#ifndef INTERRUPTDLG_H
#define INTERRUPTDLG_H

#include <QWidget>
#include <QDialog>
#include <QBitmap>
#include <QPalette>
#include <QPainter>
#include <QPixmap>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFile>
#include <QPushButton>
#include <QLabel>
#include <QString>

class InterruptDlg : public QDialog
{
    Q_OBJECT

public:
    explicit InterruptDlg(QWidget *parent = nullptr);
    ~InterruptDlg();

    void setDialogAttrbutes();
    void setBtnCloseAttributes();
    void setlabInfoAttributes();
    void setBtnKnowAttributes();

private:
    QString strWarnInfo;
    QPushButton *btnClose;
    QPushButton *btnKnow;
    QLabel *labInfo;
    QLabel *labWarnImage;
    QHBoxLayout *hlayoutClose;
    QHBoxLayout *hlayoutInfo;
    QHBoxLayout *hlayoutKnow;
    QVBoxLayout *vlayoutInterrupt;
};

#endif // INTERRUPTDLG_H
