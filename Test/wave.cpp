#include "wave.h"
#include "ui_wave.h"
#include <QDebug>
#include <QFileDialog>
#define cout qDebug()

Wave::Wave(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wave)
{
    ui->setupUi(this);
    qDebug() << "check";
    scene = new QGraphicsScene(0,0,800, 600);
//    this->setScreen(scene);
    ui->graphicsView->setScene(scene);
    pixmap = new QPixmap(800, 600);
    painter = new QPainter(pixmap);
    painter->fillRect(0,0,800,600, Qt::white);
    itempixmap = new QGraphicsPixmapItem(*pixmap);
    scene->addItem(itempixmap);

//define aimer2
    aimer[0] = new QGraphicsLineItem();
    aimer[1] = new QGraphicsLineItem();
    aimer[2] = new QGraphicsLineItem();
    pen = new QPen();
    pen->setStyle(Qt::DashLine);
    pen->setWidth(1);
    pen->setColor(Qt::black);
    aimer[0] = scene->addLine( 0, 0, 70, 70, *pen);
    aimer[2] = scene->addLine( 0, 70, 0, 70, *pen);
    pen->setColor(Qt::red);
    pen->setWidth(10);
    aimer[1] = scene->addLine(1000, 1000, 1000, 1000, *pen);
//    aimer[0]->setLine(0,20, 10000, 20);

    aimer[0]->setVisible(cur);
    aimer[1]->setVisible(cur);
    aimer[2]->setVisible(cur);



    for(int i=0; i<9; i++){
        label_v[i] = new QLabel(this);
        label_v[i]->setVisible(true);
    }
    for(int i=0; i<11; i++){
        label_h[i] = new QLabel(this);
        label_h[i]->setVisible(true);
    }

    for(int i=0; i<9; i++){
        spot_h[i] = new QGraphicsLineItem;
        spot_h[i]->setVisible(true);
        spot_h[i]->setLine(0,10+580.0/8*i,800,10+580.0/8*i);
        spot_h[i]->setPen(Qt::DashLine);
        spot_h[i]->setOpacity(0.6);
        scene->addItem(spot_h[i]);
    }
    for(int i=0; i<11; i++){
        spot_v[i] = new QGraphicsLineItem;
        spot_v[i]->setVisible(true);
        spot_v[i]->setLine((800.0/10)*i,0,(800.0/10)*i,600);
        spot_v[i]->setPen(Qt::DashLine);
        spot_v[i]->setOpacity(0.6);
        scene->addItem(spot_v[i]);
    }

//    box.setGeometry(QRect(600,300,200,200));
//    connect(&butgrp, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(myslot()));
//    connect(&butgrp, SIGNAL(id(QAbstractButton *button)), this, SLOT(myslot()));
//      connect(&butgrp, SIGNAL(QButtonGroup::idClicked(0)), this, SLOT(myslot()));
//    QButtonGroup::id(QAbstractButton *button)
}

Wave::~Wave()
{
    delete ui;
}

void Wave::gogo(){
    cout << "MASD";
}

//show//
void Wave::on_pushButton_clicked() {
    for(int i=0; i<label_vec.size(); i++){
        scene->removeItem(label_vec[i]);
    }
    label_vec.clear();
    for(int i=0; i<wave_vec.size(); i++){
        scene->removeItem(wave_vec[i]);
    }
    wave_vec.clear();
    for(int i=0; i<button_vec.size(); i++){
        box.removeItem(button_vec[i]);
        delete button_vec[i];
    }
    button_vec.clear();
    for(int i=0; i<absbut_vec.size(); i++){
        butgrp.removeButton(absbut_vec[i]);
    }



    qDebug() << "deb";
    qDebug() << circuit->all_IC[0]->value;
    Stime = std::max(1e-12, Stime);
    qDebug() << "my st" << Stime;
    for(auto x: circuit->all_node){
        for(auto V: x->Voltage)
            cout << V.real() << V.imag();
        cout << ' ';
    }
/*
    QSet<Node*> tmp, nw;
    qDebug() << "wave_node: " << circuit->wave_node.size();
    for(auto x: circuit->wave_node){
        if(!tmp.contains(circuit->rela[x])){
            nw.insert(x);
            tmp.insert(circuit->rela[x]);
        }
        for(auto V: x->Voltage)
                cout << V.real() << V.imag();
    }
    circuit->wave_node = nw;
*/
    qDebug() << "wave_node n: " << circuit->wave_node.size();
    Vmax = -1e6, Vmin = 1e6;
    int r = 0;

    QVector<IC*> vs;
    for(auto x: circuit->all_IC){
        if(x->type == "V"){
            if(x->wave_type == "SQ")
                for(int i = 0; i < 100; i ++)
                    vs.push_back(x);
            vs.push_back(x);
        }
    }
    for(int i=0; i<100; i++){
        vec[i].clear();
    }
    for(auto &x: vec)
        for(int i = 0 ; i <= 801; i++)
            x.push_back(0);
    for(auto x: circuit->wave_node){
        cout << "v_idx size :: " << x->Voltage.size();
        cout << "v_idx size :: " << x->Frequen.size();
        for(int v_idx = 0 ; v_idx < x->Voltage.size(); v_idx++){
            double R = x->Voltage[v_idx].real(), I = x->Voltage[v_idx].imag();
            qDebug()<<v_idx<<R<<I;
            double c = sqrt(R*R + I*I), d = (R==0)? ((I>0)?M_PI/2:-M_PI/2) : atan(I/(R));
            if(R<0){
                d-=M_PI;
            }

            double step = Stime/800, nt = 0, Vt;
            int idx = 0;
            cout << "CD" << c << d;
            cout << "check point1: " << v_idx;
            qDebug()<<"is_ac:"<<vs[v_idx]->wave_type;
            while(nt <= Stime){
                if(vs[v_idx]->wave_type=="AC" ||vs[v_idx]->wave_type=="SQ")
                    Vt = c*cos((x->Frequen[v_idx])*2*M_PI*nt+d);
                else
                    Vt = c*cos((x->Frequen[v_idx])*2*M_PI*nt+d+M_PI/2);
                vec[r][idx]+=Vt;
                Vmax=std::max(vec[r][idx], Vmax);
                Vmin=std::min(vec[r][idx], Vmin);
                idx++;
                nt+=step;
            }
            qDebug() <<  x->Voltage[v_idx].real();
        }
        r++;
    }
    qDebug() << "VMAXVMIN" << Vmax << Vmin;
    Vm = (Vmax+Vmin)/2;
    HOR.clear();

    pen->setStyle(Qt::SolidLine);
    pen->setWidth(1);

        for(int i=0; i<9; i++){
            label_v[i]->setText(QString::number(Vmax-(Vmax-Vmin)/8*i, 'f', 3));
            label_v[i]->setGeometry(20,15+380.0/8*i,50,25+380.0/8*i);
            label_v[i]->setVisible(true);
        }
        for(int i=0; i<11; i++){
            label_h[i]->setText(QString::number((Stime-0)/10*i, 'f', 3));
            label_h[i]->setGeometry(90+(800.0/10)*i,420,110+(800.0/10)*i,430);
            label_h[i]->setVisible(true);
        }
    for(int i = 0 ; i < circuit->wave_node.size(); i++){
        pen->setColor(col[i%10]);
        for(int j=0; j<vec[i].size()-1; j++){
            //qDebug() << 'S' << i << j << vec[i][j];
            QGraphicsLineItem* tmpl = new QGraphicsLineItem(j, 300-(vec[i][j]-Vm)/(Vmax-Vm+1e-6)*290, j+1, 300-(vec[i][j+1]-Vm)/(Vmax-Vm+1e-6)*290);
            tmpl->setPen(*pen);
            wave_vec.push_back(tmpl);
            scene->addItem(tmpl);
            if(j==0){
                QString str = "Wave_N"+QString::number(i);

                QRadioButton* tmpbut = new QRadioButton(str);
                tmpbut->setPalette(col[i]);
                butgrp.addButton(tmpbut);
                absbut_vec.push_back(tmpbut);
                box.addWidget(tmpbut);
                button_vec.push_back(box.itemAt(i));

                str = "V_N"+QString::number(i);
                QGraphicsTextItem* tmpt = new QGraphicsTextItem(str);
                tmpt->setDefaultTextColor(col[i]);
                tmpt->setPos(700,20+i*25);
                tmpt->setScale(2);
                label_vec.push_back(tmpt);
                scene->addItem(tmpt);
            }
        }
    }
//    itempixmap = new QGraphicsPixmapItem(*pixmap);
//    scene->addItem(itempixmap);
    siz = circuit->wave_node.size();
    ui->groupBox->setLayout(&box);
    ui->groupBox->setGeometry(900,240,120,button_vec.size()*30+20);
}

//save//
void Wave::on_pushButton_2_clicked() {
//    QString f_str = QFileDialog::getSaveFileName(NULL, "Save","C:\\", "All Files (*.csv)");

    QString f_str = QFileDialog::getSaveFileName(NULL, QObject::tr("Text file"),
        qApp->applicationDirPath(), QObject::tr("All Files (*.txt)"));
    QFile saveFile(f_str);

    if(!saveFile.open(QIODevice::WriteOnly| QIODevice::Text)){
        qDebug() << "Cannot save file: " << f_str;
        return;
    }
    QDataStream out(&saveFile);
    QString tmp;
    tmp += "T ,";
    for(int j = 0 ; j < siz ; j++){
        tmp += (QString::number(j+1) + " ,");
    }
    tmp += "\n";
    for(int i = 0 ; i <= 800; i ++){
        tmp += QString::number(i) + " ,";
        for(int j = 0 ; j < siz ; j++){
//            qDebug() << i << j  << vec[j][i];
            tmp += QString::number(vec[j][i]) + " ,";
        }
        tmp+="\n";
    }
    cout << tmp;
    out << tmp;
    saveFile.close();
}

//curser//
void Wave::mouseMoveEvent(QMouseEvent *event){
    cout << event->x() << event->y();
    pen->setStyle(Qt::DashLine);
    pen->setColor(Qt::black);
    int idx = std::max(std::min(900, event->x()), 100);
    aimer[0]->setLine(event->x()-100, 0, event->x()-100, 10000);
//    scene->addItem(aimer[0]);
//    QPixmap* pixmap2 = pixmap;
//    QPainter* painter2 = new QPainter(pixmap2);
//    QPen penr(Qt::red, 1);
//    painter2->setPen(penr);
//    painter2->drawLine(event->x()-100, 0, event->x()-100, 10000);
//    itempixmap = new QGraphicsPixmapItem(*pixmap2);
//    scene->addItem(itempixmap);
    if(ui->comboBox->count()){
        int sit =  300-(vec[cur_idx][idx-100]-Vm)/(Vmax-Vm+1e-6)*290;
        cout << "sit:" << sit;
        ui->label_6->setText(QString::number(vec[cur_idx][idx-100], 'f', 3));
        ui->label_9->setText(QString::number((double)(idx-100)/800*Stime, 'f', 3));
        aimer[1]->setLine(event->x()-100, sit, event->x()-100, sit+1);
        aimer[2]->setLine(0, sit, 10000, sit);
    }

}

void Wave::on_pushButton_3_clicked() {
    cur = !cur;
    aimer[0]->setVisible(cur);
    aimer[1]->setVisible(cur);
    aimer[2]->setVisible(cur);
    ui->comboBox->clear();
    if(cur) {
        for(int i = 0; i < siz; i++){
            ui->comboBox->addItem("LINE"+QString::number(i));
        }
    }
    qDebug() << cur;
}


void Wave::on_comboBox_currentIndexChanged(int index)
{
    cur_idx = index;
}

void Wave::myslot(int a){
    qDebug()<<a;
}
void Wave::myslot(QString a){
    qDebug()<<a;
}
void Wave::myslot(void){
    qDebug()<<"lalala";
}
