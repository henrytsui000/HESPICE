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

    cout << circuit->wave_node.size();
    int r = 0;
    for(auto x: circuit->wave_node){
        for(int v_idx = 0 ; v_idx < x->Voltage_SWEEP.size(); v_idx++){
            cout << "VIDX::" << v_idx ;
            double R = x->Voltage_SWEEP[v_idx].real(), I = x->Voltage_SWEEP[v_idx].imag();
            double c = sqrt(R*R + I*I), d = (R==0)? ((I>0)?M_PI/2:-M_PI/2) : atan(I/(R));
            cout << "RI:" << R << I << v_idx << c;
            vec[r].push_back(c);
            if(R<0){
                d-=M_PI;
            }
        }
        r++;
    }
    Vmax = -1e6, Vmin = 1e6;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < 101; j++){
            Vmax = std::max(Vmax, vec[i][j]);
            Vmin = std::min(Vmin, vec[i][j]);
        }
    }
    Vm = (Vmax+Vmin)/2;

    pen->setStyle(Qt::SolidLine);
    pen->setWidth(1);

    for(int i=0; i<9; i++){
        label_v[i]->setText(QString::number(Vmax-(Vmax-Vmin)/8*i, 'f', 3));
        label_v[i]->setGeometry(20,15+380.0/8*i,50,25+380.0/8*i);
        label_v[i]->setVisible(true);
    }


    for(int i = 0 ; i < circuit->wave_node.size(); i++){
        pen->setColor(col[i%10]);
        QVector<QGraphicsItem*> wave_vec_tmp;
        for(int j=0; j<vec[i].size()-1; j++){
            //qDebug() << 'S' << i << j << vec[i][j];
            QGraphicsLineItem* tmpl = new QGraphicsLineItem(j*8, 300-(vec[i][j]-Vm)/(Vmax-Vm+1e-6)*290, (j+1)*8, 300-(vec[i][j+1]-Vm)/(Vmax-Vm+1e-6)*290);
            tmpl->setPen(*pen);
            wave_vec_tmp.push_back(tmpl);
            scene->addItem(tmpl);
            if(j==0){
                QString str = "Wave_N"+QString::number(i);
                QRadioButton* tmpbut = new QRadioButton(str);
//                tmpbut->setPalette(col[i]);
                tmpbut->setAutoExclusive(false);
                tmpbut->setCheckable(true);
                tmpbut->setChecked(true);
                butgrp.addButton(tmpbut,i);
                absbut_vec.push_back(tmpbut);
                box.addWidget(tmpbut);
                button_vec.push_back(box.itemAt(i));

                str = "N"+QString::number(i);
                circuit->label_text[i]->setPlainText(str);
                circuit->label_text[i]->setDefaultTextColor(col[i]);

                str = "V_N"+QString::number(i);
                QGraphicsTextItem* tmpt = new QGraphicsTextItem(str);
                tmpt->setDefaultTextColor(col[i]);
                tmpt->setPos(700,20+i*40);
                tmpt->setScale(2);
                label_vec.push_back(tmpt);
                scene->addItem(tmpt);
            }
        }
        wave_vec.push_back(wave_vec_tmp);
    }
    siz = circuit->wave_node.size();
    ui->Cursor->setCheckable(true);
}


void Sweep::on_Cursor_clicked()
{

}

void Sweep::mouseMoveEvent(QMouseEvent *event) {
    /*
    cout << event->x() << event->y();
    pen->setStyle(Qt::DashLine);
    pen->setColor(Qt::black);
    int idx = std::max(std::min(900, event->x()), 100);
    aimer[0]->setLine(event->x()-100, 0, event->x()-100, 10000);
    if(ui->comboBox->count()){
        int sit =  300-(vec[cur_idx][idx-100]-Vm)/(Vmax-Vm+1e-6)*290;
        cout << "sit:" << sit;
        ui->label_6->setText(QString::number(vec[cur_idx][idx-100], 'f', 3));
        ui->label_9->setText(QString::number((double)(idx-100)/800*Stime, 'f', 3));
        aimer[1]->setLine(event->x()-100, sit, event->x()-100, sit+1);
        aimer[2]->setLine(0, sit, 10000, sit);
    }
    */
}


