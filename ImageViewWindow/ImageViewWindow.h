#ifndef IMAGEVIEWWINDOW_H
#define IMAGEVIEWWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QRectF>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class ImageViewWindow; }
QT_END_NAMESPACE

class ImageViewWindow : public QWidget
{
    Q_OBJECT

public:
    ImageViewWindow(QWidget *parent = nullptr);
    ~ImageViewWindow();

    void initControl();

private:
    Ui::ImageViewWindow *ui;

    QGraphicsScene *m_scene;
    QMap m_imgMapInfolst ;
};
#endif // IMAGEVIEWWINDOW_H
