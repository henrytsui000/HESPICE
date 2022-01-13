#ifndef IC_H
#define IC_H

#include <QGraphicsPixmapItem>
#include <QString>
#include <QPair>
#include "resistor.h"
#include "capacitor.h"
#include "inductor.h"
#include "voltage.h"
#include "current.h"
#include "gnd.h"
#include "node.h"
#include "setpcdialog.h"
#include "setsourcedialog.h"


class IC : public Voltage, public Current, public Resistor, public Inductor, public Capacitor, public GND
{
private:
    QString type;
    QString name;
    QPoint mouse;
    bool vertical;

    QString unit;
    double value;
    double freq;
    double phase;
    QString wave_type;

    int width;
    int height;
    QPoint center;
    Node* node_in;
    Node* node_out;
    QGraphicsPixmapItem* picitem;
    QGraphicsTextItem* textitem1;
    QGraphicsTextItem* textitem2;
    QGraphicsScene* scene;
    int rotate;
public:
    void set_pic(QString str);
    void set_center_pos(int x, int y);
    QGraphicsPixmapItem* get_pic(void);
    bool Inside(int x, int y);
    IC();
    IC(QGraphicsScene* scene, QString type);
    ~IC();
    friend class Circuit;
    friend class Setpcdialog;
    friend class Setsourcedialog;
    friend class Wave;
};

#endif // IC_H
