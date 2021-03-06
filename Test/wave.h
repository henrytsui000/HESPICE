#ifndef WAVE_H
#define WAVE_H

#include <QDialog>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QVector>
#include <QLabel>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QButtonGroup>
#include "circuit.h"

class Circuit;
namespace Ui {
class Wave;
}

class Wave : public QDialog
{
    Q_OBJECT

public:
    explicit Wave(QWidget *parent = nullptr);
    double Stime;
    ~Wave();
    Circuit* circuit;
    void gogo();

    friend class Circuit;
private slots:
    void wave_slot(int);
    void mouseMoveEvent(QMouseEvent*) override;
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    QColor col[10]{Qt::red,Qt::green,Qt::blue,Qt::darkRed,Qt::darkGreen,Qt::darkBlue,Qt::magenta,Qt::cyan,Qt::darkCyan,Qt::yellow};
    Ui::Wave *ui;
    QGraphicsScene *scene;
    QPixmap *pixmap;
    QPainter *painter;
    QGraphicsPixmapItem *itempixmap;
    QVector<QLabel*> HOR;
    QVector<QLabel*> VER;
    QVector<double> vec[100];
    int siz;
    QGraphicsLineItem *aimer[3];
    QPen *pen;
    bool cur = false;
    int cur_idx = 0;
    double Vmax = -1e6, Vmin = 1e6, Vm;

    QLabel* label_v[9];
    QLabel* label_h[11];
    QGraphicsLineItem* spot_v[9];
    QGraphicsLineItem* spot_h[11];
    QVector<QVector<QGraphicsItem*>> wave_vec;
    QVector<QGraphicsItem*> label_vec;
    QVector<QLayoutItem*> button_vec;
    QVBoxLayout box;
    QButtonGroup butgrp;
    QVector<QRadioButton*> absbut_vec;

    void closeEvent(QCloseEvent *event) override;
};

#endif // WAVE_H
