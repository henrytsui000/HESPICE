#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QObject>
#include <QMainWindow>
#include <QGraphicsLineItem>
#include <algorithm>
#include <setpcdialog.h>
#include <setsourcedialog.h>
#include "mainwindow.h"
#include <complex>
#include "node.h"
#include "wire.h"
#include "ic.h"
#include "simdialog.h"



class MainWindow;
class Circuit : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Circuit(QWidget *parent);
    ~Circuit();
    void set_op(QString type, QString mode);
    void add_op(void);
    void add_wire(void);
    void move_op(void);
    void cut_op(void);
    void check_node(void);
    void combine_node(Node** node);
    void clear_all(void);
    void add_pic(void);
    void check_connection();
    void DFS(Node* from);
    int chx(int x);
    int chy(int y);
    void run();
    std::complex<double> imp(IC*, double);
    MainWindow* w;
    Simu* simu;
    int index_is_setting;

    friend class Setpcdialog;
    friend class Setsourcedialog;
    friend class MainWindow;
    friend class Wave;
private:
    bool is_connected;
    QVector<Wire*> all_wire;
    QVector<IC*> all_IC;
    QString type;
    QString mode;
    int move_index;
    bool draw_wire;
    double scale_x;
    double scale_y;
    QPoint offset;
    QPoint mouse;
    double simu_time;
    QSet<Node*> all_node;
    QSet<Node*> wave_node;
    QSet<IC*> wave_ic;
    double freq;
    QVector<Node*> clr_node;
    QMap<Node*, Node*> rela;
    QMap<Node*, int> rela_idx;

    QGraphicsLineItem *aimer[2];
    QGraphicsPixmapItem *pic;
    QPoint pic_pos, pic_size;
    QPen *pen;
    QGraphicsScene *scene;
private slots:
    void mouseMoveEvent(QMouseEvent*) override;
    void mousePressEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void keyPressEvent(QKeyEvent*) override;
};

#endif // CIRCUIT_H
