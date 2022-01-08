#include "scopedialog.h"
#include "ui_scopedialog.h"

ScopeDialog::ScopeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScopeDialog)
{
    ui->setupUi(this);
}

ScopeDialog::~ScopeDialog()
{
    delete ui;
}
