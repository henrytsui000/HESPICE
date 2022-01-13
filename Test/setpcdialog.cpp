#include "setpcdialog.h"
#include "ui_setpcdialog.h"

Setpcdialog::Setpcdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setpcdialog)
{
    ui->setupUi(this);
}

Setpcdialog::~Setpcdialog()
{
    delete ui;
}
void Setpcdialog::initialization(IC *ic, int index){
    this->ic = ic;
    this->index = index;

    ui->lineEdit_value->setText(QString::number(ic->value));
    ui->lineEdit_name->setText(ic->name);
    mp['p'] = 1e-12;
    mp['n'] = 1e-9;
    mp['u'] = 1e-6;
    mp['m'] = 1e-3;
    mp['k'] = 1e3;
    mp['M'] = 1e6;
    mp['G'] = 1e9;
}


double Setpcdialog::chg(QString str){
    if(str.back() <= '9'){
        return str.toDouble();
    } else {
        double tmp = str.left(str.size()-1).toDouble();
        return tmp*mp[str.back()];
    }
}

void Setpcdialog::on_pushButton_ok_clicked()
{
    qDebug() << "ok_clicked";
    ic->value = chg(ui->lineEdit_value->text());
    ic->name = ui->lineEdit_name->text();
    ic->textitem1->setPlainText(ic->name);
    QString s = "";
    double tmp = ic->value;
    for(auto &x : mp.toStdMap()){
        if(ic->value >= x.second && ic->value < x.second*999.99999){
            s = x.first;
            tmp /= x.second;
            break;
        }
    }
    ic->textitem2->setPlainText(QString::number(tmp)+s+ic->unit);
    ic->text2 = QString::number(tmp)+s+ic->unit;
    this->close();
}

void Setpcdialog::on_pushButton_cancel_clicked()
{
    this->close();
}

