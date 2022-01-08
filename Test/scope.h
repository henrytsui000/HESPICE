#ifndef SCOPE_H
#define SCOPE_H

#include <QGraphicsView>
#include <QObject>
#include <QMouseEvent>

class Scope : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Scope(QWidget *parent);
    ~Scope();

private:
//    QColor col[10]{Qt::red,Qt::green,Qt::blue,Qt::darkRed,Qt::darkGreen,Qt::darkBlue,Qt::magenta,Qt::cyan,Qt::darkCyan,Qt::yellow};
//    QGraphicsScene *scene;
//    QPixmap *pixmap;
//    QPainter *painter;
//    QGraphicsPixmapItem *itempixmap;

private slots:
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // SCOPE_H
