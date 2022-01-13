#include "simu_freq.h"
#include "ui_simu_freq.h"

#include <QDebug>
Simu_freq::Simu_freq(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Simu_freq)
{
    qDebug()<<"simu_freq";
    ui->setupUi(this);
    ui->lineEdit_l->setText("1");
    ui->lineEdit_h->setText("10");
    mp['m'] = 1e-3;
    mp['u'] = 1e-6;
    mp['n'] = 1e-9;
    mp['p'] = 1e-12;
    mp['k'] = 1e3;
    mp['M'] = 1e6;
    mp['G'] = 1e9;
}

Simu_freq::~Simu_freq()
{
    delete ui;
}

void Simu_freq::on_pushButton_clicked()
{
    QString str_l = ui->lineEdit_l->text();
    QString str_h = ui->lineEdit_h->text();

    if(str_l.back() <= '9'){
        freq_l = str_l.toDouble();
    } else {
        double tmp = str_l.left(str_l.size()-1).toDouble();
        freq_l = tmp*mp[str_l.back()];
    }
    qDebug() << "freq_l: " << freq_l;

    if(str_h.back() <= '9'){
        freq_h = str_h.toDouble();
    } else {
        double tmp = str_h.left(str_h.size()-1).toDouble();
        freq_h = tmp*mp[str_h.back()];
    }
    qDebug() << "freq_l: " << freq_l;

    if(freq_l<freq_h){
        w->fre_l = freq_l;
        w->fre_h = freq_h;
        w->on_actionSWEEP_2();
        this->close();
    }
}

