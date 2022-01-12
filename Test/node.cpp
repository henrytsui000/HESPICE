#include "node.h"

Node::Node()
{
    visit=false;
    connect=1;
    p.setX(0);
    p.setY(0);
    wire = new QVector<Wire*>;
    ic = new QVector<IC*>;
    pen = new QPen();
    pointitem = new QGraphicsLineItem();
    pointitem->setPen(*pen);
    pen->setColor(Qt::green);
    pen->setStyle(Qt::SolidLine);
    pen->setWidth(10);
}
Node::Node(QGraphicsScene* scene)
{
    this->scene = scene;
    visit=false;
    connect=1;
    p.setX(0);
    p.setY(0);
    wire = new QVector<Wire*>;
    ic = new QVector<IC*>;
    pen = new QPen();
    pointitem = new QGraphicsLineItem();
    pointitem->setPen(*pen);
    pen->setColor(Qt::green);
    pen->setWidth(10);
    pointitem = scene->addLine(QLine(p,p),*pen);
}

Node::~Node(){
    scene->removeItem(pointitem);
    delete wire;
    delete ic;
    delete pointitem;
    delete pen;

}
void Node::set_node(){
    pointitem->setLine(QLine(p,p));
    pointitem->setZValue(1);
}
