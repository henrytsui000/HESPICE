 #include "ic.h"

IC::IC()
{
    node_in = new Node();
    node_out = new Node();
    vertical = true;
    rotate=0;
    value=0;
    freq=0;
    phase=0;
}
IC::IC(QGraphicsScene* scene, QString type)
{
    node_in = new Node(scene);
    node_out = new Node(scene);
    this->scene = scene;
    vertical = true;
    rotate=0;
    value=0;
    freq=0;
    phase=0;

    set_pic(type);
}
void IC::set_pic(QString str){
    QPixmap* tmp;
    type=str;
    if(str == "R"){
        qDebug()<<"ADD R";
        tmp=new QPixmap("image/R.png");
//        tmp=new QPixmap("D:/NYCU/S3/AOOP/FP/pro1216/build-Test-Desktop_Qt_6_1_3_MinGW_64_bit-Debug/R.png");
        unit="Ω";
    } else if(str == "C"){
        tmp=new QPixmap("image/C.png");
        unit="F";
    } else if(str == "L"){
        tmp=new QPixmap("image/L.png");
        unit="H";
    } else if(str == "V"){
        tmp=new QPixmap("image/V.png");
        unit="V";
        wave_type = "DC";
    } else if(str == "I"){
        tmp=new QPixmap("image/I.png");
        unit="A";
        wave_type = "DC";
    }else if(str == "AV"){
        tmp=new QPixmap("image/AV.png");
    }else if(str == "G"){
        tmp=new QPixmap("image/GND.png");
        node_out->p.setX(-10000);
        node_out->p.setY(-10000);
    }else{
        qDebug()<<"set_pic error: ";
    }

    picitem = new QGraphicsPixmapItem(*tmp);
    width=tmp->width();
    height=tmp->height();
    picitem->setOffset(QPoint(0,0));
    scene->addItem(picitem);

    if(type!="G"){
        name = type;
        textitem1 = new QGraphicsTextItem(name);
        scene->addItem(textitem1);
        textitem1->setScale(2);
        textitem1->setZValue(2);

        textitem2 = new QGraphicsTextItem(QString::number(value));
        text2 = QString::number(value);
        scene->addItem(textitem2);
        textitem2->setScale(2);
        textitem2->setZValue(2);
    }
}
void IC::set_center_pos(int x, int y){
    mouse.setX(x);
    mouse.setY(y);
    QPoint tmp[2];
    if(rotate==0){
        tmp[0] = QPoint(x,y)-QPoint(0,height/2), tmp[1] = QPoint(x,y)+QPoint(0,height/2);
    } else if(rotate==1){
        tmp[0] = QPoint(x,y)+QPoint(height/2,0), tmp[1] = QPoint(x,y)-QPoint(height/2,0);
    } else if(rotate==2){
        tmp[0] = QPoint(x,y)-QPoint(0,-height/2), tmp[1] = QPoint(x,y)+QPoint(0,-height/2);
    }else if(rotate==3){
        tmp[0] = QPoint(x,y)-QPoint(-height/2,0), tmp[1] = QPoint(x,y)+QPoint(-height/2,0);
    }

    tmp[0] = QPoint((tmp[0].x()+20)-(tmp[0].x()+20)%40,(tmp[0].y()+20)-(tmp[0].y()+20)%40);
    tmp[1] = QPoint((tmp[1].x()+20)-(tmp[1].x()+20)%40,(tmp[1].y()+20)-(tmp[1].y()+20)%40);

    if(type!="G"){
        node_in->p=tmp[0];
        node_out->p=tmp[1];
    } else{
        node_in->p=tmp[0];
        if(rotate==3) node_in->p -= QPoint(40,0);
    }

    node_in->set_node();
    node_out->set_node();

    center.setX((tmp[0].x()+tmp[1].x())/2);
    center.setY((tmp[0].y()+tmp[1].y())/2);


    x=(center.x()-width/2);
    y=(center.y()-height/2);
    this->picitem->setPos(x,y);
    if(type!="G"){
        if(rotate%2==0){
            this->textitem1->setPos(center.x()+width/2, center.y()-height/2-10);
            this->textitem2->setPos(center.x()+width/2, center.y()+height/2-40);
        } else if(rotate%2==1){
            this->textitem1->setPos(center.x()+height/2, center.y()-width/2-10);
            this->textitem2->setPos(center.x()+height/2, center.y()+width/2-40);
        }
    }
}
QGraphicsPixmapItem* IC::get_pic(void){
    return picitem;
}
bool IC::Inside(int x, int y){
    if(rotate%2==0){
        if(x<center.x()-width/2 || x>center.x()+width/2){
            return false;
        } else if(y<center.y()-height/2 || y>center.y()+height/2){
            return false;
        }
        return true;
    } else{
        if(x<center.x()-height/2 || x>center.x()+height/2){
            return false;
        } else if(y<center.y()-width/2 || y>center.y()+width/2){
            return false;
        }
        return true;
    }
}
IC::~IC(){

    for(int j=0; j<node_in->wire->size(); j++){
        if(node_in->ic->at(j) == this){
            node_in->ic->erase(node_in->ic->begin()+j);
            break;
        }
    }
    for(int j=0; j<node_out->wire->size(); j++){
        if(node_out->ic->at(j) == this){
            node_out->ic->erase(node_out->ic->begin()+j);
            break;
        }
    }

    node_in->connect--;
    node_out->connect--;
    if(node_in->connect==0) delete node_in;
    if(node_out->connect==0) delete node_out;

    scene->removeItem(picitem);
    if(type!="G"){
        scene->removeItem(textitem1);
        scene->removeItem(textitem2);
    }
}
