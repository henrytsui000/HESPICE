#include "sweep.h"
#include "ui_sweep.h"

#define cout qDebug()

Sweep::Sweep(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sweep)
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


    aimer[0] = new QGraphicsLineItem();
    aimer[1] = new QGraphicsLineItem();
    aimer[2] = new QGraphicsLineItem();
    pen = new QPen();
    pen->setStyle(Qt::DashLine);
    pen->setWidth(1);
    pen->setColor(Qt::black);
    aimer[0] = scene->addLine( 0, 0, 0, 0, *pen);
    aimer[2] = scene->addLine( 0, 0, 0, 0, *pen);
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
        spot_h[i]->setOpacity(0.2);
        scene->addItem(spot_h[i]);
    }
    for(int i=1; i<11; i++){
        spot_v[i] = new QGraphicsLineItem;
        spot_v[i]->setVisible(true);
        spot_v[i]->setLine((800.0/10)*i,0,(800.0/10)*i,600);
        spot_v[i]->setPen(Qt::DashLine);
        spot_v[i]->setOpacity(0.2);
        scene->addItem(spot_v[i]);
    }

}

Sweep::~Sweep()
{
    delete ui;
}


void Sweep::on_Show_clicked()
{
    for(int i=0; i<100; i++) vec[i].clear();
    for(auto &x: vec)
        for(int i = 0 ; i <= 801; i++)
            x.push_back(0);

    cout << circuit->wave_node.size();
    int r = 0;
    for(auto x: circuit->wave_node){
        for(int v_idx = 0 ; v_idx < x->Voltage_SWEEP.size(); v_idx++){
            cout << "VIDX::" << v_idx ;
            double R = x->Voltage_SWEEP[v_idx].real(), I = x->Voltage_SWEEP[v_idx].imag();
            cout << "RI:" << R << I;
            double c = sqrt(R*R + I*I), d = (R==0)? ((I>0)?M_PI/2:-M_PI/2) : atan(I/(R));
            for(int i = 0; i < 20; i++){
                cout << r << v_idx << c*cos(i*10/x->Frequen[v_idx]);
            }
            double Vt = c*cos(2*M_PI/(x->Frequen[v_idx])/4+d);
            vec[r][v_idx]+=Vt;
//            cout << r << v_idx << Vt << x->Frequen[v_idx];
        }
        r++;
    }
}


void Sweep::on_Cursor_clicked()
{

}

