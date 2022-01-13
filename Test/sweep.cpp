#include "sweep.h"
#include "ui_sweep.h"

Sweep::Sweep(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sweep)
{
    ui->setupUi(this);
}

Sweep::~Sweep()
{
    delete ui;
}
