#include "scope.h"

Scope::Scope(QWidget *parent): QGraphicsView(parent)
{

}

Scope::~Scope(){

}
void Scope::mouseMoveEvent(QMouseEvent *event){
    qDebug() << event->x() << event->y();

}
