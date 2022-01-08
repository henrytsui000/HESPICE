#include "wire.h"
#include "node.h"

Wire::Wire()
{
    node[0] = new Node();
    node[1] = new Node();
    pen = new QPen();
    lineitem = new QGraphicsLineItem();

    pen->setColor(Qt::red);
    pen->setWidth(3);
    lineitem->setPen(*pen);
}
Wire::Wire(QGraphicsScene* scene)
{
    node[0] = new Node();
    node[1] = new Node();
    pen = new QPen();
    lineitem = new QGraphicsLineItem();

    pen->setColor(Qt::red);
    pen->setWidth(3);
    lineitem->setPen(*pen);

    line.setPoints(node[0]->p,node[1]->p);
    lineitem->setLine(line);
    scene->addItem(lineitem);
    this->scene = scene;
}
Wire::~Wire(){
    node[0]->connect--;
    node[1]->connect--;
    if(node[0]->connect==0) delete node[0];
    if(node[1]->connect==0) delete node[1];

    scene->removeItem(lineitem);
    delete lineitem;
    delete pen;
}
void Wire::set_pos(int n, int x, int y){
    if(n==0){
        node[0]->p.setX((x+20)-(x+20)%40);
        node[0]->p.setY((y+20)-(y+20)%40);
    } else {
        if(abs(x-node[0]->p.x())>=abs(y-node[0]->p.y())){
            node[1]->p.setY(node[0]->p.y());
            node[1]->p.setX((x+20)-(x+20)%40);
        } else{
            node[1]->p.setX(node[0]->p.x());
            node[1]->p.setY((y+20)-(y+20)%40);
        }

        line.setPoints(node[0]->p,node[1]->p);
        lineitem->setLine(line);
        node[0]->set_node();
        node[1]->set_node();

        diff=node[1]->p-node[0]->p;
    }
}

void Wire::set_center_pos(int x, int y){
    QPoint tmp[2];
    tmp[0] = QPoint(x,y)-diff/2;
    tmp[1] = QPoint(x,y)+diff/2;

    for(int i=0; i<2; i++){
        set_pos(i,tmp[i].x(),tmp[i].y());
    }
    //line.setPoints(node[0]->p,node[1]->p);
    //lineitem->setLine(line);
}

bool Wire::Inside(int x, int y){
    x+=6;
    y+=6;
    int tmp=8;
    if(abs(x-node[0]->p.x())<tmp){
        if(y>qMin(node[0]->p.y(),node[1]->p.y())-tmp && y<qMax(node[0]->p.y(),node[1]->p.y())+tmp){
            return true;
        }
    }
    if(abs(y-node[0]->p.y())<tmp){
        if(x>qMin(node[0]->p.x(),node[1]->p.x())-tmp && x<qMax(node[0]->p.x(),node[1]->p.x())+tmp){
            return true;
        }
    }
    return false;
}
