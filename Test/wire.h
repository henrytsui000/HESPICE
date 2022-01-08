#ifndef WIRE_H
#define WIRE_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QPoint>
#include <QLine>
#include <algorithm>
class Node;
class Wire
{
public:
    Node* node[2];
    QLine line;
    QPoint diff;
    Wire();
    Wire(QGraphicsScene* scene);
    ~Wire();
    void set_pos(int n, int x, int y);
    void set_center_pos(int x, int y);
    QPen* pen;
    QGraphicsLineItem* lineitem;
    QGraphicsScene* scene;
    bool Inside(int x, int y);
};

#endif // WIRE_H
