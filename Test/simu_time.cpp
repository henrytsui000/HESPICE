#include "simu_time.h"
#include "ui_simu_time.h"

#include <QDebug>
simu_time::simu_time(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::simu_time)
{
    qDebug()<<"simu_time";
    ui->setupUi(this);
    ui->lineEdit->setText("1");
    mp['m'] = 1e-3;
    mp['u'] = 1e-6;
    mp['n'] = 1e-9;
    mp['p'] = 1e-12;
    mp['k'] = 1e3;
    mp['M'] = 1e6;
    mp['G'] = 1e9;
}

simu_time::~simu_time()
{
    delete ui;
}

void simu_time::on_pushButton_clicked() {
    QString str = ui->lineEdit->text();
    qDebug() << str.back() << '9' << (str.back() <= '9') ;
    if(str.back() <= '9'){
        Stime = str.toDouble();
        qDebug() <<"SS"<< Stime;
    } else {
        double tmp = str.left(str.size()-1).toDouble();
        Stime = tmp*mp[str.back()];
    }
    qDebug() << "simu time: " << Stime;
    w->Stime = Stime;
    this->close();
}

