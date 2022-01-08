#include "simdialog.h"
#include "ui_simdialog.h"

Simdialog::Simdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Simdialog)
{
    ui->setupUi(this);
}

Simdialog::~Simdialog()
{
    delete ui;
}
