#ifndef NODE_H
#define NODE_H

#include"wire.h"
#include"ic.h"
#include<QVector>
#include<QPoint>
#include<QLine>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <complex>
class IC;
class Wire;
class Node
{
public:
    bool visit;
    QPoint p;
    int connect;
    QVector<Wire*> *wire;
    QVector<IC*> *ic;    
    QPen *pen;
    QGraphicsLineItem *pointitem;
    Node();
    Node(QGraphicsScene* scene);
    ~Node();
    void set_node();
    QVector<std::complex<double>> Voltage;
    QVector<std::complex<double>> Current;
    QVector<double> Frequen;
};

#endif // NODE_H
