#include "simu.h"
#include "ui_simu.h"

Simu::Simu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Simu)
{
    ui->setupUi(this);
}

Simu::~Simu()
{
    delete ui;
}

void Simu::on_pushButton_clicked()
{

}

