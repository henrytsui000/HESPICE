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

    pic = NULL;
    mode = "NONE";
    type = "NONE";
    action_index = -1;
    selected_index = -1;
    draw_wire = false;
}

Circuit::~Circuit(){
    qDebug() <<"delete Circuit";
}

int Circuit::chx(int x){
    return 4999+(x-width()/2)/scale_x+offset.x();
}

int Circuit::chy(int y){
    return 4999+(y-height()/2)/scale_y+offset.y();
}

void Circuit::set_op(QString type, QString mode){
    this->mode = mode;
    this->type = type;
    if(this->mode=="ADD" && type!="W") add_op();
    else if(this->mode=="ADD" && type=="W") add_wire();
    else if(this->mode=="MOVE") ;
    else if(this->mode=="CLEAR") clear_all();
    else if(this->mode=="IMAGE") add_pic();
    else if(this->mode=="SAVE") save_file();
    else if(this->mode=="OPEN") open_file();
    else if(this->mode=="WAVE") is_showing_wave = true;
    else if(this->mode=="SWEEP") is_showing_sweep = true;
    qDebug()<<"succcess set_op "<<mode<<" "<<type;
}

void Circuit::save_file(){

    QString filter = "(*.hesp)";
    QString fileName = QFileDialog::getSaveFileName
            (this, "Save", QDir::currentPath(), filter);
    qDebug()<<fileName;

    ofstream fout(fileName.toStdString(), ios::out);
    fout << "HESPICE:\n";
    fout << all_wire.size()<< "\n";
    for(int i=0; i<all_wire.size(); i++){
        fout << "W";
        fout << " " << all_wire[i]->node[0]->p.x();
        fout << " " << all_wire[i]->node[0]->p.y();
        fout << " " << all_wire[i]->node[1]->p.x();
        fout << " " << all_wire[i]->node[1]->p.y();
        fout << "\n";
    }
    fout << all_IC.size()<< "\n";
    for(int i=0; i<all_IC.size(); i++){
        fout << all_IC[i]->type.toStdString();
        if(all_IC[i]->type != "G") {
            fout << " " << all_IC[i]->name.toStdString();
            fout << " " << all_IC[i]->unit.toStdString();
            if(all_IC[i]->type == "V" || all_IC[i]->type == "I")
                fout << " " << all_IC[i]->wave_type.toStdString();
            fout << " " << all_IC[i]->value;
            fout << " " << all_IC[i]->freq;
            fout << " " << all_IC[i]->phase;
            fout << "\n";
            fout << all_IC[i]->text2.toStdString();
            fout << "\n";
        }
        fout << " " << all_IC[i]->rotate;
        fout << " " << all_IC[i]->node_in->p.x();
        fout << " " << all_IC[i]->node_in->p.y();
        if(all_IC[i]->type != "G"){
            fout << " " << all_IC[i]->node_out->p.x();
            fout << " " << all_IC[i]->node_out->p.y();
        }
        fout <<"\n";
    }
    fout <<"end";

    fout.close();
    mode = "NONE";
    type = "NONE";
    end_last();
}
void Circuit::open_file(){
    QString filter = "(*.hesp)";
    QString fileName = QFileDialog::getOpenFileName
            (this, "Open", QDir::currentPath(), filter);
    qDebug()<<fileName;

    ifstream fin(fileName.toStdString(), ios::in);
    if(!fin){
        qDebug()<<"wrong format";
        mode = "NONE";
        type = "NONE";
        end_last();
    }

//    QString tmp_str;
    string tmp_str;
    int tmp_int, tmp_size, tmpx, tmpy, tmpx2, tmpy2;
    double tmp_double;
    fin >> tmp_str;
    if(tmp_str != "HESPICE:"){
        fin.close();
        qDebug()<<"wrong format";
        mode = "NONE";
        type = "NONE";
        end_last();
    }

    fin>>tmp_size;
    for(int i=0; i<tmp_size; i++){
        qDebug()<<"add_wire";
        fin>>tmp_str;
        Wire* tmp = new Wire(scene);
        tmp->node[0]->wire->push_back(tmp);
        tmp->node[1]->wire->push_back(tmp);
        all_wire.push_back(tmp);

        fin >> tmpx;
        fin >> tmpy;
        all_wire.back()->set_pos(0 ,tmpx, tmpy);
        fin >> tmpx;
        fin >> tmpy;
        all_wire.back()->set_pos(1 ,tmpx, tmpy);
        combine_node(&tmp->node[0]);
        combine_node(&tmp->node[1]);
    }  
    fin>>tmp_size;
    for(int i=0; i<tmp_size; i++){
        qDebug()<<"add_op";
        fin>>tmp_str;
        IC* tmp = new IC(scene, QString::fromStdString(tmp_str));
        tmp->node_in->ic->push_back(tmp);
        tmp->node_out->ic->push_back(tmp);
        all_IC.push_back(tmp);

        if(all_IC.back()->type != "G") {
            fin >> tmp_str;
            all_IC.back()->name = QString::fromStdString(tmp_str);
            fin >> tmp_str;
            all_IC.back()->unit = QString::fromStdString(tmp_str);
            if(all_IC.back()->type == "V" || all_IC.back()->type == "I"){
                fin >> tmp_str;
                all_IC.back()->wave_type = QString::fromStdString(tmp_str);
            }
            fin >> all_IC.back()->value;
            fin >> all_IC.back()->freq;
            fin >> all_IC.back()->phase;

            getline(fin, tmp_str);
            getline(fin, tmp_str);
            all_IC.back()->text2 = QString::fromStdString(tmp_str);
            all_IC.back()->textitem1->setPlainText(all_IC.back()->name);
            all_IC.back()->textitem2->setPlainText(all_IC.back()->text2);
        }
        fin >> tmp_int;
        for(int i=0; i<tmp_int; i++){
            QTransform trans = all_IC.back()->picitem->transform();
            int w = all_IC.back()->width/2;
            int h = all_IC.back()->height/2;
            trans.translate(w+h, h-w);
            all_IC.back()->rotate=(all_IC.back()->rotate+1)%4;
            trans.rotate(90);
            all_IC.back()->picitem->setTransform(trans);
        }
        fin >> tmpx;
        fin >> tmpy;

        if(all_IC.back()->type != "G"){
            fin >> tmpx2;
            fin >> tmpy2;
            tmpx = (tmpx + tmpx2)/2;
            tmpy = (tmpy + tmpy2)/2;
        } else {
            if(all_IC.back()->rotate==0) tmpy +=20;
            else if(all_IC.back()->rotate==1) tmpx -=20;
            else if(all_IC.back()->rotate==2) tmpy -=20;
            else if(all_IC.back()->rotate==3) tmpx +=20;
        }
        all_IC.back()->set_center_pos(tmpx,tmpy);
        combine_node(&tmp->node_in);
        combine_node(&tmp->node_out);
    }
    fin >> tmp_str;
    if(tmp_str=="end"){
        qDebug()<<"success read file";
    }
    fin.close();

    mode = "NONE";
    type = "NONE";
    end_last();
}
/*
QTransform trans = all_IC[action_index]->picitem->transform();
int w = all_IC[action_index]->width/2;
int h = all_IC[action_index]->height/2;
trans.translate(w+h, h-w);
all_IC[action_index]->rotate=(all_IC[action_index]->rotate+1)%4;
trans.rotate(90);
all_IC[action_index]->picitem->setTransform(trans);
all_IC[action_index]->set_center_pos(all_IC[action_index]->mouse.x(),all_IC[action_index]->mouse.y());
*/


void Circuit::add_pic(){
    if(pic != NULL){
        scene->removeItem(pic);
        delete pic;
    }
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
    end_last();
}

void Circuit::clear_all(){
    QList<QGraphicsItem*> l = scene->items();
    for(int i=0; i<l.size(); i++){
        scene->removeItem(l[i]);
    }
    scene->addItem(aimer[0]);
    scene->addItem(aimer[1]);

    all_IC.clear();
    all_wire.clear();
    delete pic;
    pic = NULL;
    end_last();
}

void Circuit::add_op(){
    qDebug()<<"add_op";
    IC* tmp = new IC(scene, type);
    tmp->node_in->ic->push_back(tmp);
    tmp->node_out->ic->push_back(tmp);
    all_IC.push_back(tmp);
}

void Circuit::add_wire(){
    qDebug()<<"add_wire";
    Wire* tmp=new Wire(scene);
    tmp->node[0]->wire->push_back(tmp);
    tmp->node[1]->wire->push_back(tmp);
    all_wire.push_back(tmp);

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

QString Circuit::check_connection(){
    is_connected = true;
    can_sweep = true;
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
    if(is_connected == false) return "uncompleted circuit";

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
    if(is_connected == false) return "not connected to ground";

    for(int i=0; i<all_IC.size(); i++){
        if(all_IC[i]->type == "V"){
            if(all_IC[i]->wave_type!="AC"){
                can_sweep = false;
                return "not sine wave cannot sweep";
            }
        }
    }
    return "NONE";
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
    } else if(mode=="MOVE" && action_index!=-1){
        if(type=="IC") all_IC[action_index]->set_center_pos(chx(event->x()), chy(event->y()));
        if(type=="W") all_wire[action_index]->set_center_pos(chx(event->x()), chy(event->y()));
        if(type=="P"){
            pic_pos.setX(chx(event->x())-pic_size.x()/2);
            pic_pos.setY(chy(event->y())-pic_size.y()/2);
            pic->setPos(pic_pos);
        }
    } else if(mode=="MOVE" || mode=="CUT" || mode=="WAVE" || mode=="NONE"|| mode=="SWEEP"){
        QList<QGraphicsItem*> l = scene->items();
        type = "NONE";
        selected_index = -1;
        for(int i=0; i<l.size(); i++){
            l[i]->setOpacity(1);
        }
        for(int i=all_wire.size()-1; i>=0; i--){
            if(all_wire[i]->Inside(chx(event->x()), chy(event->y()))){
                all_wire[i]->lineitem->setOpacity(0.2);
                type = "W";
                selected_index = i;
                return;
            }
        }
        for(int i=all_IC.size()-1; i>=0; i--){
            if(all_IC[i]->Inside(chx(event->x()),chy(event->y()))){
                all_IC[i]->picitem->setOpacity(0.3);
                type = "IC";
                selected_index = i;
                return;
            }
        }
        if(pic!=NULL){
            if(pic_pos.x()<chx(event->x()) && pic_pos.x()+pic_size.x()>chx(event->x()) &&
               pic_pos.y()<chy(event->y()) && pic_pos.y()+pic_size.y()>chy(event->y())){
                pic->setOpacity(0.3);
                type = "P";
                selected_index = 0;
                return;
            }
        }
    }
    if(mode == "NONE"){
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
        } else if(mode=="MOVE" && action_index==-1 && selected_index!=-1){
            action_index = selected_index;
            int i = action_index;
            selected_index = -1;
            qDebug()<<selected_index<<type<<mode;
            if(type == "W"){
                for(int j=0; j<2; j++){
                    if(all_wire[i]->node[j]->connect!=1){
                        for(int k=0; k<all_wire[i]->node[j]->wire->size(); k++){
                            if(all_wire[i]->node[j]->wire->at(k)==all_wire[i])
                                all_wire[i]->node[j]->wire->erase(all_wire[i]->node[j]->wire->begin()+k);
                        }
                        all_wire[i]->node[j]->connect--;
                        all_wire[i]->node[j] = new Node(scene);
                        all_wire[i]->node[j]->wire->push_back(all_wire[i]);
                    }
                }
            }
            else if(type == "IC"){
                if(all_IC[i]->node_in->connect!=1){
                    for(int j=0; j<all_IC[i]->node_in->ic->size(); j++){
                        if(all_IC[i]->node_in->ic->at(j)==all_IC[i])
                            all_IC[i]->node_in->ic->erase(all_IC[i]->node_in->ic->begin()+j);
                    }
                    all_IC[i]->node_in->connect--;
                    all_IC[i]->node_in = new Node(scene);
                    all_IC[i]->node_in->ic->push_back(all_IC[i]);
                }
                if(all_IC[i]->node_out->connect!=1){
                    for(int j=0; j<all_IC[i]->node_out->ic->size(); j++){
                        if(all_IC[i]->node_out->ic->at(j)==all_IC[i])
                            all_IC[i]->node_out->ic->erase(all_IC[i]->node_out->ic->begin()+j);
                    }
                    all_IC[i]->node_out->connect--;
                    all_IC[i]->node_out = new Node(scene);
                    all_IC[i]->node_out->ic->push_back(all_IC[i]);
                }
            }

        } else if(mode=="MOVE" && action_index!=-1){
            if(type=="IC"){
                combine_node(&all_IC[action_index]->node_in);
                combine_node(&all_IC[action_index]->node_out);
            } else if(type=="W"){
                combine_node(&all_wire[action_index]->node[0]);
                combine_node(&all_wire[action_index]->node[1]);
            }
            action_index=-1;
        } else if(mode=="CUT" && selected_index!=-1){
            int i = selected_index;
            if(type == "W"){
                delete all_wire[i];
                all_wire.erase(all_wire.begin()+i);
                return;
            }
            else if(type == "IC"){
                delete all_IC[i];
                all_IC.erase(all_IC.begin()+i);
                return;
            }
            else if(type =="P"){
                scene->removeItem(pic);
                delete pic;
                pic = NULL;
            }
        } else if(mode=="NONE"){
            qDebug()<<"NONE";
            mouse.setX(event->x());
            mouse.setY(event->y());
        } else if(mode=="WAVE" || mode == "SWEEP"){
            qDebug()<<mode;
            int i = selected_index;
            if(type=="W"){
                bool add = true;
                for(int j=0; j<wave_node.size(); j++){
                    if(rela[wave_node[j]]==rela[all_wire[i]->node[0]]){
                        add = false;
                        wave_node.erase(wave_node.begin()+j);
                        scene->removeItem(label_text[j]);
                        delete label_text[j];
                        label_text.erase(label_text.begin()+j);
                        break;
                    }
                }
                if(add){
                    QGraphicsTextItem* tmp = new QGraphicsTextItem("N"+QString::number(label_text.size()));
                    label_text.push_back(tmp);
                    tmp->setScale(2);
                    tmp->setPos((all_wire[i]->node[0]->p + all_wire[i]->node[1]->p)/2);
                    scene->addItem(tmp);
                    wave_node.push_back(all_wire[i]->node[0]);
                }
                qDebug()<<"wave_node"<<i;
            }
            else if(type=="IC"){
                wave_ic.insert(all_IC[i]);
                qDebug()<<"wave_ic"<<i;
            }
            if(mode=="WAVE")
                wave->on_pushButton_clicked();
            if(mode=="SWEEP"){
                swp->on_Show_clicked();
            }
        }
    } else if(event->button() == Qt::RightButton){
        if(mode=="NONE"){
            if(type=="IC"){
                int i = selected_index;
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
                type = "NONE";
                selected_index = -1;
            }
        } else if(mode=="ADD" && type=="W" && draw_wire){
            delete all_wire.back();
            all_wire.erase(all_wire.end()-1);
            add_wire();
            draw_wire=false;
        } else {
            if(mode=="ADD" && type=="W"){
                delete all_wire.back();
                all_wire.erase(all_wire.end()-1);
                aimer[0]->setVisible(false);
                aimer[1]->setVisible(false);
            } else if(mode=="ADD"){
                delete all_IC.back();
                all_IC.erase(all_IC.end()-1);
            }
            mode = "NONE";
            type = "NONE";
            selected_index = -1;
            action_index = -1;
            w->set_all_unchecked();
        }
    }
}
void Circuit::end_last(){
    if(mode=="ADD" && type=="W" && draw_wire){
        delete all_wire.back();
        all_wire.erase(all_wire.end()-1);
        add_wire();
        draw_wire=false;
        end_last();
    } else {
        if(mode=="ADD" && type=="W"){
            delete all_wire.back();
            all_wire.erase(all_wire.end()-1);
            aimer[0]->setVisible(false);
            aimer[1]->setVisible(false);
        } else if(mode=="ADD"){
            delete all_IC.back();
            all_IC.erase(all_IC.end()-1);
        }
        mode = "NONE";
        type = "NONE";
        selected_index = -1;
        action_index = -1;
        w->set_all_unchecked();
    }
}
void Circuit::mouseReleaseEvent(QMouseEvent *event){
    mouse.setX(-1);
    mouse.setY(-1);
}
void Circuit::keyPressEvent(QKeyEvent *event){
    if(event->key()=='R'){
        if((mode=="MOVE" && action_index!=-1 && type!="W" && type!="P")||(mode=="ADD" && type!="W" && type!="P")){
            if(mode=="ADD")
                action_index = all_IC.size()-1;
            QTransform trans = all_IC[action_index]->picitem->transform();
            int w = all_IC[action_index]->width/2;
            int h = all_IC[action_index]->height/2;
            trans.translate(w+h, h-w);
            all_IC[action_index]->rotate=(all_IC[action_index]->rotate+1)%4;
            trans.rotate(90);
            all_IC[action_index]->picitem->setTransform(trans);
            all_IC[action_index]->set_center_pos(all_IC[action_index]->mouse.x(),all_IC[action_index]->mouse.y());
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
        x->Voltage_SWEEP.clear();
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

void Circuit::sweep(){
    qDebug() << "i'm running SwEeP!";

    wave_node.clear();
    QVector<IC*> vs, cp;

    for(auto x: all_IC){
        if(x->type == "V"){
            vs.push_back(x);
        } else if(x->type != "G"){
            cp.push_back(x);
        }
    }
    all_node.clear();
    for(auto x: all_wire){
        all_node.insert(x->node[0]);
        all_node.insert(x->node[1]);
    }
    for(auto x: all_node){
        x->Voltage.clear();
        x->Voltage_SWEEP.clear();
        x->Current.clear();
        x->Frequen.clear();
    }
    cout << "SSS:"<< ssf << sef;
    ssf = w->fre_l, sef = w->fre_h;
    cout << ssf << sef;
    qDebug()<<"run for loop";
    for(int v_idx = 0 ; v_idx < vs.size(); v_idx++){

        clr_node.clear();
        rela.clear();
        rela_idx.clear();

        QQueue<Node*> sta;

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
        for(int st = 0; st <= 100; st++) {
            int MSZ = clr_node.size()+1;
            complex<double> **Z = new complex<double>*[MSZ];

            rep(i, MSZ){
                Z[i]=new complex<double>[MSZ];
                rep(j, MSZ)
                    Z[i][j] = 0;
            }
            double freq_tmp = vs[v_idx]->freq;

            double now_sf = log(sef/ssf)*st/100;
            now_sf = pow(M_E, now_sf)*ssf;
            cout << "pow :" << now_sf ;
            vs[v_idx]->freq = now_sf;
            for(int i = 0; i < cp.size(); i++) {
                int a = rela_idx[rela[cp[i]->node_in]];
                int b = rela_idx[rela[cp[i]->node_out]];
                Z[a][b] -= imp(cp[i], vs[v_idx]->freq);
                Z[b][a] -= imp(cp[i], vs[v_idx]->freq);

                Z[a][a] += imp(cp[i], vs[v_idx]->freq);
                Z[b][b] += imp(cp[i], vs[v_idx]->freq);
            }
            cout << "check point1: " << now_sf;

            int a = rela_idx[rela[vs[v_idx]->node_in]];
            int b = rela_idx[rela[vs[v_idx]->node_out]];
            Z[MSZ-1][a] = Z[a][MSZ-1] = 1;
            Z[MSZ-1][b] = Z[b][MSZ-1] = -1;

            rep(i, MSZ){
                rep(j, MSZ){
                    cout << Z[i][j].real() << ' ' << Z[i][j].imag();
                }
                cout << ' ' ;
            }
            MSZ--;
            complex<double> **Zp = new complex<double>*[MSZ];
            rep(i, MSZ){
                Zp[i]=new complex<double>[MSZ];
                rep(j, MSZ){
                    Zp[i][j] = Z[i+(gnd_idx<=i)][j+(gnd_idx<=j)];
                }
            }


            complex<double> V[MSZ];
            V[MSZ-1] = complex<double>(vs[v_idx]->value*cos(vs[v_idx]->phase-M_PI/2),
                                       vs[v_idx]->value*sin(vs[v_idx]->phase-M_PI/2));
            complex<double> **inverse=new complex<double>*[MSZ];
            for(int i=0;i<MSZ;i++){
                inverse[i]=new complex<double>[MSZ];
            }
            tools::getInverse(Zp,inverse,MSZ);

            complex<double> *result=new complex<double>[MSZ];
            rep(i, MSZ){
                result[i] = 0;
                rep(j, MSZ)
                    result[i] += inverse[i][j]*V[j];
            }

            for(auto &x: all_node){
                int idx = rela_idx[rela[x]];
                if(idx != gnd_idx){
                    x->Voltage_SWEEP.push_back(result[idx - (idx >= gnd_idx)]);
                    x->Frequen.push_back(vs[v_idx]->freq);
//                    cout << x->Voltage[v_idx].real() << result[rela_idx[rela[x]]].real();
                }else {
                    x->Voltage_SWEEP.push_back(0);
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
