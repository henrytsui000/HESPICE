#include "circuit.h"
#include <QVector>
#include <complex>
#include <QStack>
#include <QQueue>
#include "tools.h"

#define rep(i, n) for(int i = 0; i < (int)n;i++)
using namespace std;
#define cout qDebug()

Circuit::Circuit(QWidget *parent): QGraphicsView(parent)
{
    setMouseTracking(true);
    qDebug()<<"build Circuit";
    //scene = new QGraphicsScene(0,0,998,598);
    scene = new QGraphicsScene();
    scene->setSceneRect(5000,5000,2,2);
    this->setScene(scene);

    aimer[0] = new QGraphicsLineItem();
    aimer[1] = new QGraphicsLineItem();
    pen = new QPen();
    pen->setStyle(Qt::DashLine);
    pen->setWidth(1);
    pen->setColor(Qt::black);
    aimer[0] = scene->addLine(0,0,0,0, *pen);
    aimer[1] = scene->addLine(0,0,0,0, *pen);

    aimer[0]->setVisible(false);
    aimer[1]->setVisible(false);

    scale_x=1;
    scale_y=1;

    mouse.setX(-1);
    mouse.setY(-1);

    offset.setX(0);
    offset.setY(0);

    mode="NONE";
}

Circuit::~Circuit(){
    qDebug() <<"delete Circuit";
}
//width/2+(event.x()-width/2)/scale_x
//width/2+(event.x()-width/2)/scale_x

int Circuit::chx(int x){
    //return offset_x + width()/2+(x-width()/2)/scale_x;
    //return scene->width()/2 + (x - width()/2)/scale_x + width()/2;
    return 4999+(x-width()/2)/scale_x+offset.x();
}
int Circuit::chy(int y){
//    return offset_y + height()/2+(y-height()/2)/scale_y;
    //return scene->height()/2 + (y - height()/2)/scale_y + height()/2;
    return 4999+(y-height()/2)/scale_y+offset.y();
}

void Circuit::set_op(QString type, QString mode){
    this->mode=mode;
    this->type=type;
    if(this->mode=="ADD" && type!="W") add_op();
    else if(this->mode=="ADD" && type=="W") draw_wire=false, add_wire();
    else if(this->mode=="MOVE") move_index=-1;
    else if(this->mode=="CLEAR") clear_all();
    else if(this->mode=="IMAGE") add_pic();
    qDebug()<<"succcess set_op "<<mode<<" "<<type;
}
void Circuit::add_pic(){
    if(pic) scene->removeItem(pic);

    QString str = QFileDialog::getOpenFileName(this);
    if(str=="") return;

    QPixmap* tmp;
    tmp = new QPixmap(str);
    *tmp = tmp->scaled(300,300,Qt::KeepAspectRatio);

    pic_size.setX(tmp->width());
    pic_size.setY(tmp->height());

    pic_pos.setX(4500);
    pic_pos.setY(4700);
    pic = new QGraphicsPixmapItem(*tmp);
    pic->setPos(pic_pos);
    scene->addItem(pic);
    mode="NONE";
}
void Circuit::clear_all(){
    for(int i=0; i<all_IC.size(); i++){
        scene->removeItem(all_IC[i]->picitem);
        scene->removeItem(all_IC[i]->node_in->pointitem);
        scene->removeItem(all_IC[i]->node_out->pointitem);
        scene->removeItem(all_IC[i]->textitem1);
        scene->removeItem(all_IC[i]->textitem2);
    }
    for(int i=0; i<all_wire.size(); i++){
        scene->removeItem(all_wire[i]->lineitem);
        scene->removeItem(all_wire[i]->node[0]->pointitem);
        scene->removeItem(all_wire[i]->node[1]->pointitem);
    }
    all_IC.clear();
    all_wire.clear();
    scene->removeItem(pic);
}

void Circuit::add_op(){
    qDebug()<<"add_op";
    IC* tmp = new IC(scene);
    tmp->node_in->ic->push_back(tmp);
    tmp->node_out->ic->push_back(tmp);
    tmp->node_in->pointitem = scene->addLine(20, 20, 20, 20, *tmp->node_in->pen);
    tmp->node_out->pointitem = scene->addLine(20, 20, 20, 20, *tmp->node_out->pen);
    tmp->set_pic(type);
    tmp->set_center_pos(-100,-100);

    all_IC.push_back(tmp);
//    all_node.push_back(tmp->node_in);
//    all_node.push_back(tmp->node_out);
}
void Circuit::add_wire(){
    Wire* tmp=new Wire(scene);
    tmp->node[0]->wire->push_back(tmp);
    tmp->node[1]->wire->push_back(tmp);
    //tmp->lineitem = scene->addLine(20, 20, 20, 20, *tmp->pen);
    scene->addItem(tmp->lineitem);
    tmp->node[0]->pointitem = scene->addLine(20, 20, 20, 20, *tmp->node[0]->pen);
    tmp->node[1]->pointitem = scene->addLine(20, 20, 20, 20, *tmp->node[1]->pen);

    all_wire.push_back(tmp);
//    all_node.push_back(tmp->node[0]);
//    all_node.push_back(tmp->node[1]);
}

void Circuit::combine_node(Node **node){
    for(int i=0; i<all_IC.size(); i++){
        if(all_IC[i]->node_in->p==(*node)->p && all_IC[i]->node_in!=(*node)){
            *all_IC[i]->node_in->wire += *(*node)->wire;
            *all_IC[i]->node_in->ic += *(*node)->ic;
            all_IC[i]->node_in->connect += (*node)->connect;
            scene->removeItem((*node)->pointitem);
            delete (*node);
            (*node)=all_IC[i]->node_in;
            return;
        }
        if(all_IC[i]->node_out->p==(*node)->p && all_IC[i]->node_out!=(*node)){
            *all_IC[i]->node_out->wire += *(*node)->wire;
            *all_IC[i]->node_out->ic += *(*node)->ic;
            all_IC[i]->node_out->connect += (*node)->connect;
            scene->removeItem((*node)->pointitem);
            delete (*node);
            (*node)=all_IC[i]->node_out;
            return;
        }
    }
    for(int i=0; i<all_wire.size(); i++){
        for(int j=0; j<2; j++){
            if(all_wire[i]->node[j]->p==(*node)->p && all_wire[i]->node[j]!=(*node) && all_wire[i]->node[1-j]!=(*node)){
                *all_wire[i]->node[j]->wire += *(*node)->wire;
                *all_wire[i]->node[j]->ic += *(*node)->ic;
                all_wire[i]->node[j]->connect += (*node)->connect;
                scene->removeItem((*node)->pointitem);
                delete (*node);
                (*node)=all_wire[i]->node[j];
                return;
            }
        }
    }
}

void Circuit::check_connection(){
    is_connected=true;
    for(int i=0; i<all_IC.size(); i++){
        all_IC[i]->node_in->visit=false;
        all_IC[i]->node_out->visit=false;
        if(all_IC[i]->node_in->connect<2) is_connected=false;
        if(all_IC[i]->node_in->connect<2) is_connected=false;
    }
    for(int i=0; i<all_wire.size(); i++){
        all_wire[i]->node[0]->visit=false;
        all_wire[i]->node[1]->visit=false;
        if(all_wire[i]->node[0]->connect<2) is_connected=false;
        if(all_wire[i]->node[1]->connect<2) is_connected=false;
    }
    for(int i=0; i<all_IC.size(); i++){
        if(all_IC[i]->type=="G") DFS(all_IC[i]->node_in);
    }
    for(int i=0; i<all_IC.size(); i++){
        if(all_IC[i]->node_in->visit==false)  is_connected=false;
        if(all_IC[i]->node_out->visit==false)  is_connected=false;
    }
    for(int i=0; i<all_wire.size(); i++){
        if(all_wire[i]->node[0]->visit==false) is_connected=false;
        if(all_wire[i]->node[1]->visit==false) is_connected=false;
    }
    qDebug()<<"is_connected:"<<is_connected;
}
void Circuit::DFS(Node* from){
    from->visit=true;
    IC* tmp_ic;
    Wire* tmp_wire;
    for(int i=0; i<from->ic->size(); i++){
        tmp_ic=from->ic->at(i);
        if(tmp_ic->node_in!=from && tmp_ic->node_in->visit==false) DFS(tmp_ic->node_in);
        if(tmp_ic->node_out!=from && tmp_ic->node_out->visit==false) DFS(tmp_ic->node_out);
    }
    for(int i=0; i<from->wire->size(); i++){
        tmp_wire=from->wire->at(i);
        if(tmp_wire->node[0]!=from &&tmp_wire->node[0]->visit==false) DFS(tmp_wire->node[0]);
        if(tmp_wire->node[1]!=from &&tmp_wire->node[1]->visit==false) DFS(tmp_wire->node[1]);
    }
}

/*
void Circuit::check_node(void){
    for(int i=0; i<all_node.size(); i++){
        for(int j=i; j<all_node.size(); j++){
            if(all_node[i]->x==all_node[j]->x && all_node[i]->y==all_node[j]->y){
                for(int k=0; k<all_IC.size(); k++){
                    if(all_IC[k]->node_in==all_node[j]) all_IC[k]->node_in=all_node[i];
                    if(all_IC[k]->node_out==all_node[j]) all_IC[k]->node_out=all_node[i];
                }
                for(int k=0; k<all_wire.size(); k++){
                    if(all_wire[k]->node[0]==all_node[j]) all_wire[k]->node[0]=all_node[i];
                    if(all_wire[k]->node[1]==all_node[j]) all_wire[k]->node[1]=all_node[i];
                }
                *all_node[i]->ic += *all_node[j]->ic;
                *all_node[i]->wire += *all_node[j]->wire;
                all_node.erase(all_node.begin()+j);
            }
        }
    }
}
*/

void Circuit::mouseMoveEvent(QMouseEvent *event){
    if(mode=="ADD" && type=="W"){
        if(draw_wire){
            all_wire.back()->set_pos(1,chx(event->x()), chy(event->y()));
        } else{
            all_wire.back()->set_pos(0,chx(event->x()), chy(event->y()));
            all_wire.back()->set_pos(1,chx(event->x()), chy(event->y()));
        }
        aimer[0]->setLine(0,all_wire.back()->node[1]->p.y(),10000,all_wire.back()->node[1]->p.y());
        aimer[1]->setLine(all_wire.back()->node[1]->p.x(),0,all_wire.back()->node[1]->p.x(),10000);
        aimer[0]->setVisible(true);
        aimer[1]->setVisible(true);
    } else if(mode=="ADD"){
        all_IC.back()->set_center_pos(chx(event->x()), chy(event->y()));
    } else if(mode=="MOVE" && move_index!=-1){
        if(type=="IC") all_IC[move_index]->set_center_pos(chx(event->x()), chy(event->y()));
        if(type=="W") all_wire[move_index]->set_center_pos(chx(event->x()), chy(event->y()));
        if(type=="P"){
            pic_pos.setX(chx(event->x())-pic_size.x()/2);
            pic_pos.setY(chy(event->y())-pic_size.y()/2);
            pic->setPos(pic_pos);
        }
    } else if(mode=="MOVE" ||mode=="CUT"||mode=="WAVE"){
        for(int i=all_wire.size()-1; i>=0; i--){
            if(all_wire[i]->Inside(chx(event->x()), chy(event->y()))){
                all_wire[i]->lineitem->setOpacity(0.2);
            } else {
                all_wire[i]->lineitem->setOpacity(1);
            }
        }
        for(int i=all_IC.size()-1; i>=0; i--){
            if(all_IC[i]->Inside(chx(event->x()),chy(event->y()))){
                all_IC[i]->picitem->setOpacity(0.3);
            } else{
                all_IC[i]->picitem->setOpacity(1);
            }
        }
        if(pic){
            if(pic_pos.x()<chx(event->x()) && pic_pos.x()+pic_size.x()>chx(event->x()) &&
               pic_pos.y()<chy(event->y()) && pic_pos.y()+pic_size.y()>chy(event->y())){
                pic->setOpacity(0.3);
            }
            else pic->setOpacity(1);
        }

    } else if(mode == "NONE"){
        if(mouse.x()!=-1 && mouse.y()!=-1){
            offset.setX(offset.x()-(event->x()-mouse.x())/scale_x);
            offset.setY(offset.y()-(event->y()-mouse.y())/scale_y);
            scene->setSceneRect(5000+offset.x(),5000+offset.y(),2,2);
            this->setScene(scene);
            mouse.setX(event->x());
            mouse.setY(event->y());
        }
    }
    scene->update();
}
void Circuit::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        if(mode=="ADD" && type=="W"){
                if(draw_wire){
                    combine_node(&all_wire.back()->node[1]);
                    add_wire();
                    scene->removeItem(all_wire.back()->node[0]->pointitem);
                    delete all_wire.back()->node[0];
                    all_wire.back()->node[0]=all_wire[all_wire.size()-2]->node[1];
                    all_wire.back()->node[0]->connect++;
                    all_wire.back()->node[0]->wire->push_back(all_wire.back());
                }else{
                    draw_wire=true;
                    combine_node(&all_wire.back()->node[0]);
                }

        } else if(mode=="ADD"){
            combine_node(&all_IC.back()->node_in);
            combine_node(&all_IC.back()->node_out);
            add_op();
            all_IC.back()->set_center_pos(chx(event->x()), chy(event->y()));
        } else if(mode=="MOVE" && move_index==-1){
            for(int i = all_IC.size()-1 ; i >=0; i--){
                if(all_IC[i]->Inside(chx(event->x()), chy(event->y()))){
                    this->move_index = i;
                    type="IC";
                    if(all_IC[i]->node_in->connect!=1){
                        for(int j=0; j<all_IC[i]->node_in->ic->size(); j++){
                            if(all_IC[i]->node_in->ic->at(j)==all_IC[i]) all_IC[i]->node_in->ic->erase(all_IC[i]->node_in->ic->begin()+j);
                        }
                        all_IC[i]->node_in->connect--;
                        all_IC[i]->node_in = new Node(scene);
                        all_IC[i]->node_in->ic->push_back(all_IC[i]);
                    }
                    if(all_IC[i]->node_out->connect!=1){
                        for(int j=0; j<all_IC[i]->node_out->ic->size(); j++){
                            if(all_IC[i]->node_out->ic->at(j)==all_IC[i]) all_IC[i]->node_out->ic->erase(all_IC[i]->node_out->ic->begin()+j);
                        }
                        all_IC[i]->node_out->connect--;
                        all_IC[i]->node_out = new Node(scene);
                        all_IC[i]->node_out->ic->push_back(all_IC[i]);
                    }
                    return;
                }
            }
            for(int i = all_wire.size()-1 ; i >=0; i--){
                if(all_wire[i]->Inside(chx(event->x()), chy(event->y()))){
                    this->move_index = i;
                    for(int j=0; j<2; j++){
                        if(all_wire[i]->node[j]->connect!=1){
                            for(int k=0; k<all_wire[i]->node[j]->wire->size(); k++){
                                if(all_wire[i]->node[j]->wire->at(k)==all_wire[i]) all_wire[i]->node[j]->wire->erase(all_wire[i]->node[j]->wire->begin()+k);
                            }
                            all_wire[i]->node[j]->connect--;
                            all_wire[i]->node[j] = new Node(scene);
                            all_wire[i]->node[j]->wire->push_back(all_wire[i]);
                        }
                    }
                    type="W";
                    return;
                }
            }
            if(pic_pos.x()<chx(event->x()) && pic_pos.x()+pic_size.x()>chx(event->x()) &&
               pic_pos.y()<chy(event->y()) && pic_pos.y()+pic_size.y()>chy(event->y())){
                this->move_index = -2;
                type = "P";
                qDebug()<<"pic_select";
            }
        } else if(mode=="MOVE" && move_index!=-1){
            if(type=="IC"){
                combine_node(&all_IC[move_index]->node_in);
                combine_node(&all_IC[move_index]->node_out);
            } else if(type=="W"){
                combine_node(&all_wire[move_index]->node[0]);
                combine_node(&all_wire[move_index]->node[1]);
            }
            move_index=-1;
        } else if(mode=="CUT"){
            for(int i = all_IC.size()-1 ; i >=0; i--){
                if(all_IC[i]->Inside(chx(event->x()), chy(event->y()))){
          //          scene->removeItem(all_IC[i]->picitem);
                    if(all_IC[i]->node_in->connect==1){
                        scene->removeItem(all_IC[i]->node_in->pointitem);
                    } else{
                        for(int j=0; j<all_IC[i]->node_in->ic->size(); j++){
                            if(all_IC[i]->node_in->ic->at(j)==all_IC[i]) all_IC[i]->node_in->ic->erase(all_IC[i]->node_in->ic->begin()+j);
                        }
                    }
                    if(all_IC[i]->node_out->connect==1){
                        scene->removeItem(all_IC[i]->node_out->pointitem);
                    } else{
                        for(int j=0; j<all_IC[i]->node_out->ic->size(); j++){
                            if(all_IC[i]->node_out->ic->at(j)==all_IC[i]) all_IC[i]->node_out->ic->erase(all_IC[i]->node_out->ic->begin()+j);
                        }
                    }
                    delete all_IC[i];
                    all_IC.erase(all_IC.begin()+i);
                    return;
                }
            }
            for(int i = all_wire.size()-1 ; i >=0; i--){
                if(all_wire[i]->Inside(chx(event->x()), chy(event->y()))){
//                    scene->removeItem(all_wire[i]->lineitem);
                    for(int j=0; j<2; j++){
                        if(all_wire[i]->node[j]->connect!=1){
                            for(int k=0; k<all_wire[i]->node[j]->wire->size(); k++){
                                if(all_wire[i]->node[j]->wire->at(k)==all_wire[i]) all_wire[i]->node[j]->wire->erase(all_wire[i]->node[j]->wire->begin()+k);
                            }
                        } else{
                            scene->removeItem(all_wire[i]->node[j]->pointitem);
                        }
                    }
                    delete all_wire[i];
                    all_wire.erase(all_wire.begin()+i);
                    return;
                }
            }
            if(pic){
                if(pic_pos.x()<chx(event->x()) && pic_pos.x()+pic_size.x()>chx(event->x()) &&
                   pic_pos.y()<chy(event->y()) && pic_pos.y()+pic_size.y()>chy(event->y())){
                    scene->removeItem(pic);
                    delete pic;
                }
            }
        } else if(mode=="NONE"){
            qDebug()<<"NONE";
            mouse.setX(event->x());
            mouse.setY(event->y());
            //offset.setX(offset.x()/scale_x);
            //offset.setY(offset.y()/scale_y);
        } else if(mode=="WAVE"){
            qDebug()<<"WAVE";
            for(int i = all_wire.size()-1 ; i >=0; i--){
                if(all_wire[i]->Inside(chx(event->x()), chy(event->y()))){

                    wave_node.insert(all_wire[i]->node[0]);
                    qDebug()<<"wave_node"<<i;
                    w->draw();
                    return;
                }
            }
            for(int i = all_IC.size()-1; i>=0; i--){
                if(all_IC[i]->Inside(chx(event->x()), chy(event->y()))){
                    wave_ic.insert(all_IC[i]);
                    qDebug()<<"wave_ic"<<i;
                    return ;
                }
            }
        }
    } else if(event->button() == Qt::RightButton){
        if(mode=="ADD" && type=="W"){
            if(draw_wire){
//                scene->removeItem(all_wire.back()->lineitem);
                if(all_wire.back()->node[0]->connect==1) scene->removeItem(all_wire.back()->node[0]->pointitem);
                if(all_wire.back()->node[1]->connect==1) scene->removeItem(all_wire.back()->node[1]->pointitem);
                all_wire.back()->node[0]->wire->erase(all_wire.back()->node[0]->wire->end()-1);
                delete all_wire.back();
                all_wire.erase(all_wire.end()-1);
                add_wire();
                draw_wire=false;
            } else{
//                scene->removeItem(all_wire.back()->lineitem);
                if(all_wire.back()->node[0]->connect==1) scene->removeItem(all_wire.back()->node[0]->pointitem);
                if(all_wire.back()->node[1]->connect==1) scene->removeItem(all_wire.back()->node[1]->pointitem);
                delete all_wire.back();
                all_wire.erase(all_wire.end()-1);
                mode="NONE";
                w->set_all_unchecked();
                aimer[0]->setVisible(false);
                aimer[1]->setVisible(false);
            }
        } else if(mode=="ADD"){
//            scene->removeItem(all_IC.back()->picitem);
            if(all_IC.back()->node_in->connect==1) scene->removeItem(all_IC.back()->node_in->pointitem);
            if(all_IC.back()->node_out->connect==1) scene->removeItem(all_IC.back()->node_out->pointitem);
            delete all_IC.back();
            all_IC.erase(all_IC.end()-1);
            mode="NONE";
            w->set_all_unchecked();
        } else if(mode=="MOVE"){
            move_index=-1;
            mode="NONE";
            w->set_all_unchecked();
        } else if(mode=="CUT"){
            mode="NONE";
            w->set_all_unchecked();
        } else if(mode=="NONE"){
            for(int i=0; i<all_IC.size(); i++){
                if(all_IC[i]->Inside(chx(event->x()), chy(event->y()))){
                    if(all_IC[i]->type=="R" || all_IC[i]->type=="L" || all_IC[i]->type=="C"){
                        Setpcdialog setpcdialog;
                        setpcdialog.initialization(all_IC[i], i);
                        setpcdialog.setModal(true);
                        setpcdialog.exec();
                    } else if(all_IC[i]->type=="V" || all_IC[i]->type=="I" ){
                        Setsourcedialog setsourcedialog;
                        setsourcedialog.initialization(all_IC[i], i);
                        setsourcedialog.setModal(true);
                        setsourcedialog.exec();
                    }
                }
            }
        }
    }

}
void Circuit::mouseReleaseEvent(QMouseEvent *event){
    mouse.setX(-1);
    mouse.setY(-1);
}
void Circuit::keyPressEvent(QKeyEvent *event){
    if(event->key()=='R'){
        if((mode=="MOVE" && move_index!=-1 && type!="W")||(mode=="ADD" && type!="W")){
            if(mode=="ADD" && type!="W") move_index=all_IC.size()-1;
            QTransform trans = all_IC[move_index]->picitem->transform();
            int w = all_IC[move_index]->width/2;
            int h = all_IC[move_index]->height/2;
            trans.translate(w+h, h-w);
            all_IC[move_index]->rotate=(all_IC[move_index]->rotate+1)%4;
            trans.rotate(90);
            all_IC[move_index]->picitem->setTransform(trans);
            qDebug()<<"success";
            all_IC[move_index]->set_center_pos(all_IC[move_index]->mouse.x(),all_IC[move_index]->mouse.y());
        }
    }
    if(event->key()=='V' || event->key()=='v') w->on_actionV_triggered();
    if(event->key()=='I' || event->key()=='i') w->on_actionI_triggered();
    if(event->key()=='L' || event->key()=='l') w->on_actionL_triggered();
    if(event->key()=='O' || event->key()=='o') w->on_actionR_triggered();
    if(event->key()=='C' || event->key()=='c') w->on_actionC_triggered();
    if(event->key()=='G' || event->key()=='g') w->on_actionGND_triggered();
    if(event->key()=='W' || event->key()=='w') w->on_actionWIRE_triggered();
    if(event->key()=='D' || event->key()=='d') w->on_actionCUT_triggered();
    if(event->key()=='M' || event->key()=='m') w->on_actionMOVE_triggered();
    if(event->key()=='+') w->on_actionZOOM_IN_triggered();
    if(event->key()=='-') w->on_actionZOOM_OUT_triggered();
    int kk;
}

complex<double> Circuit::imp(IC *p, double f){
    complex<double> one(1, 0);
    double w = acos(-1)*2*f;
    if(p->type=="C") return one/(one/complex<double> (0, w*p->value));
    else if(p->type=="L") return one/complex<double> (0, w*p->value);
    else if(p->type=="R") return one/complex<double> (p->value, 0);
    else qDebug() << "error";
    return complex<double> (0, 0);
}

void Circuit::run(){
    qDebug() << "i'm running!";

    wave_node.clear();
    QVector<IC*> vs, cp;

    for(auto x: all_IC){
        if(x->type == "V"){
            vs.push_back(x);
        } else if(x->type != "G"){
            cp.push_back(x);
        }
    }
    qDebug() << vs.size() << ' ' << cp.size();
    qDebug() << all_wire.size();
    qDebug() << all_IC.size();

    all_node.clear();
    for(auto x: all_wire){
        all_node.insert(x->node[0]);
        all_node.insert(x->node[1]);
    }

//    for(auto x: all_IC){
//        all_node.insert(x->node_in);
//        if(x->type != "G")
//            all_node.insert(x->node_out);
//    }

    for(auto x: all_node){
        x->Voltage.clear();
        x->Current.clear();
        x->Frequen.clear();
    }

    qDebug()<<"run for loop";
    for(int v_idx = 0 ; v_idx < vs.size(); v_idx++){

//  QVector<Node*> clr_node;
//  QMap<Node*, Node*> rela;
//  QMap<Node*, int> rela_idx;
//  rela :: all_node -> clr_node

        clr_node.clear();
        rela.clear();
        rela_idx.clear();

        QQueue<Node*> sta;

        //short others VS

        qDebug() << "all IC size: " << all_IC.size();
        int idx = 0;
        for(auto x: all_node){
            if(!rela[x]){
                clr_node.append(new Node);
                rela[x] = clr_node.back();
                rela_idx[clr_node.back()] = idx++;
                sta.append(x);
                while(sta.size() > 0){
                    for(auto y: *sta.front()->wire){
                        for(int i = 0 ; i < 2; i++){
                            if(!rela[y->node[i]]){
                                rela[y->node[i]] = rela[x];
                                sta.append(y->node[i]);
                            }
                        }
                    }
                    for(auto y: *sta.front()->ic){
                        if(y->type=="V" || y->type=="I"){
                            if(y==vs[v_idx]){
                                clr_node.back()->ic->push_back(y);
                            } else {
                                if(y->node_in != sta.front() && !rela[y->node_in]){
                                    rela[y->node_in] = rela[x];
                                    sta.append(y->node_in);
                                }
                                if(y->node_out != sta.front() && !rela[y->node_out]){
                                    rela[y->node_out] = rela[x];
                                    sta.append(y->node_out);
                                }
                            }
                        }
                    }
                    sta.pop_front();
                }
            }
        }
        qDebug() << "clr_node.size" << clr_node.size();
        for(auto x: clr_node){
            qDebug() << "this node: ";
            for(auto y: *x->ic)
                qDebug() << y->name;
        }

        int gnd_idx;
        for(auto x: all_IC){
            if(x->type == "G")
                gnd_idx = rela_idx[rela[x->node_in]];
        }

        //gogo

    //    freq = 1/M_PI;
        int ft_time = vs[v_idx]->wave_type == "SQ" ? 200:1;
        double rp = vs[v_idx]->wave_type == "SQ" ? 4/M_PI:1;
//        int ft = 1;
        for(int ft = 1; ft <= ft_time; ft+=2) {
            int MSZ = clr_node.size()+1;
            complex<double> **Z = new complex<double>*[MSZ];

        //    complex<double> Z[MSZ+1][MSZ+1];

            rep(i, MSZ){
                Z[i]=new complex<double>[MSZ];
                rep(j, MSZ)
                    Z[i][j] = 0;
            }
            double freq_tmp = vs[v_idx]->freq;
            vs[v_idx]->freq *= ft;
            cout <<vs[v_idx]->value << vs[v_idx]->freq << vs[v_idx]->phase;
            for(int i = 0; i < cp.size(); i++) {
                int a = rela_idx[rela[cp[i]->node_in]];
                int b = rela_idx[rela[cp[i]->node_out]];
                Z[a][b] -= imp(cp[i], vs[v_idx]->freq);
                Z[b][a] -= imp(cp[i], vs[v_idx]->freq);

                Z[a][a] += imp(cp[i], vs[v_idx]->freq);
                Z[b][b] += imp(cp[i], vs[v_idx]->freq);
            }
            cout << "check point1: " << ft;

            int a = rela_idx[rela[vs[v_idx]->node_in]];
            int b = rela_idx[rela[vs[v_idx]->node_out]];
            Z[MSZ-1][a] = Z[a][MSZ-1] = 1;
            Z[MSZ-1][b] = Z[b][MSZ-1] = -1;
            cout << "AB" << a << b;
            cout << "check point2: " << ft;

            rep(i, MSZ){
                rep(j, MSZ){
                    cout << Z[i][j].real() << ' ' << Z[i][j].imag();
                }
                cout << ' ' ;
            }
            MSZ--;

            cout << "check point3: " << ft;

            complex<double> **Zp = new complex<double>*[MSZ];
            rep(i, MSZ){
                Zp[i]=new complex<double>[MSZ];
                rep(j, MSZ){
                    Zp[i][j] = Z[i+(gnd_idx<=i)][j+(gnd_idx<=j)];
                }
            }

            cout << "check point4: " << ft;
            cout << "GND:" << gnd_idx;
            cout << "---------------------";
            rep(i, MSZ){
                rep(j, MSZ){
                    cout << Zp[i][j].real() << ' ' << Zp[i][j].imag();
                }
                cout << ' ' ;
            }

            complex<double> V[MSZ];
            V[MSZ-1] = complex<double>(vs[v_idx]->value*rp/ft*cos(vs[v_idx]->phase*ft-M_PI/2),
                                       vs[v_idx]->value*rp/ft*sin(vs[v_idx]->phase*ft-M_PI/2));
            cout << "pha"<<vs[v_idx]->phase*ft;
            cout << "V:";
            rep(i, MSZ){
                cout << V[i].real() << ' ' << V[i].imag();
            }

            complex<double> **inverse=new complex<double>*[MSZ];
            for(int i=0;i<MSZ;i++){
                inverse[i]=new complex<double>[MSZ];
            }
            tools::getInverse(Zp,inverse,MSZ);
            cout << "inv::";
            rep(i, MSZ){
                rep(j, MSZ){
                    cout << inverse[i][j].real() << ' ' << inverse[i][j].imag();
                }
                cout << ' ' ;
            }
            complex<double> *result=new complex<double>[MSZ];
            rep(i, MSZ){
                result[i] = 0;
                rep(j, MSZ)
                    result[i] += inverse[i][j]*V[j];
            }
            rep(i, MSZ){
                cout << i << "node: " << result[i].real() << '+' << result[i].imag();
            }


            for(auto &x: all_node){
                int idx = rela_idx[rela[x]];
                if(idx != gnd_idx){
                    x->Voltage.push_back(result[idx - (idx >= gnd_idx)]);
                    x->Frequen.push_back(vs[v_idx]->freq);
                    cout << x->Voltage[v_idx].real() << result[rela_idx[rela[x]]].real();
                }else {
                    x->Voltage.push_back(0);
                    x->Frequen.push_back(vs[v_idx]->freq);
                }
            }
            vs[v_idx]->freq = freq_tmp;

            //endend
            rep(i, MSZ){
                delete [] inverse[i];
                delete [] Zp[i];
            }
            delete [] Zp;
            delete [] inverse;
            delete [] result;
            rep(i, MSZ+1)
                delete [] Z[i];
            delete [] Z;

        }
    }

    QQueue<Node*> sta;
    int idx = 0;

    rela.clear();
    rela_idx.clear();
    clr_node.clear();
    for(auto x: all_node){
        if(!rela[x]){
            clr_node.append(new Node);
            rela[x] = clr_node.back();
            rela_idx[clr_node.back()] = idx++;
            sta.append(x);
            while(sta.size() > 0){
                for(auto y: *sta.front()->wire){
                    for(int i = 0 ; i < 2; i++){
                        if(!rela[y->node[i]]){
                            rela[y->node[i]] = rela[x];
                            sta.append(y->node[i]);
                        }
                    }
                }
                for(auto y: *sta.front()->ic){
                    clr_node.back()->ic->push_back(y);
                }
                sta.pop_front();
            }
        }
    }
    cout << "CKS" << clr_node.size();
}
