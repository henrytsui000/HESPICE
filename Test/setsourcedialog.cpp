#include "setsourcedialog.h"
#include "ui_setsourcedialog.h"

Setsourcedialog::Setsourcedialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setsourcedialog)
{
    ui->setupUi(this);
    ui->radioButton_DC->setChecked(true);
}

Setsourcedialog::~Setsourcedialog()
{
    delete ui;
}

double Setsourcedialog::chg(QString str){
    if(str.back() <= '9'){
        return str.toDouble();
    } else {
        double tmp = str.left(str.size()-1).toDouble();
        return tmp*mp[str.back()];
    }
}

void Setsourcedialog::initialization(IC *ic, int index){
    this->ic = ic;
    this->index = index;

    ui->lineEdit_name->setText(ic->name);
    ui->lineEdit_value->setText(QString::number(ic->value));
    ui->lineEdit_freq->setText(QString::number(ic->freq));
    ui->lineEdit_phase->setText(QString::number(ic->phase));

    ui->lineEdit_freq->setEnabled(false);
    ui->lineEdit_phase->setEnabled(false);

    if(ic->wave_type=="DC"){
        ui->radioButton_DC->setChecked(true);
        on_radioButton_DC_clicked();
    }
    if(ic->wave_type=="AC"){
        ui->radioButton_AC->setChecked(true);
        on_radioButton_AC_clicked();
    }
    if(ic->wave_type=="SQ"){
        ui->radioButton_SQ->setChecked(true);
        on_radioButton_SQ_clicked();
    }

    mp['p'] = 1e-12;
    mp['n'] = 1e-9;
    mp['u'] = 1e-6;
    mp['m'] = 1e-3;
    mp['k'] = 1e3;
    mp['M'] = 1e6;
    mp['G'] = 1e9;
}

void Setsourcedialog::on_pushButton_OK_clicked()
{
    ic->value = chg(ui->lineEdit_value->text());
    ic->name = ui->lineEdit_name->text();
    if(ic->wave_type == "DC"){
        ic->freq = 1e-9;
        ic->phase = 0;
    } else{
        ic->freq = chg(ui->lineEdit_freq->text());
        ic->phase = ui->lineEdit_phase->text().toDouble();
    }

    ic->textitem1->setPlainText(ic->name);
    if(ic->type == "V" || ic->type == "A"){
        QString s[3];
        double tmp[3] = {ic->value, ic->freq, ic->phase};
        for(auto &x : mp.toStdMap()){
            for(int i=0; i<2; i++){
                if(tmp[i] >= x.second && tmp[i] < x.second*1000){
                    s[i] = x.first;
                    tmp[i] /= x.second;
                    break;
                }
            }
        }
        QString str;
        if(ic->wave_type=="AC")
            str = "Sin " + QString::number(tmp[0]) + s[0] + ic->unit + ", " + QString::number(tmp[1]) + s[1] + "(1/s), " + QString::number(tmp[2]) + "rad";
        else if(ic->wave_type=="SQ"){
            str = "Squ " + QString::number(tmp[0]) + s[0] + ic->unit + ", " + QString::number(tmp[1]) + s[1] + "(1/s), " + QString::number(tmp[2]) + "rad";
        }
        if(ic->wave_type == "DC")
            str = "DC " + QString::number(tmp[0]) + s[0] + ic->unit;
        ic->textitem2->setPlainText(str);
        ic->text2 = str;
    }

    this->close();
}


void Setsourcedialog::on_pushButton_Cancel_clicked()
{
    this->close();
}


void Setsourcedialog::on_radioButton_DC_clicked()
{
    ui->lineEdit_freq->setEnabled(false);
    ui->lineEdit_phase->setEnabled(false);
    ic->wave_type = "DC";

}


void Setsourcedialog::on_radioButton_AC_clicked()
{
    ui->lineEdit_freq->setEnabled(true);
    ui->lineEdit_phase->setEnabled(true);
    ic->wave_type = "AC";
}


void Setsourcedialog::on_radioButton_SQ_clicked()
{
    ui->lineEdit_freq->setEnabled(true);
    ui->lineEdit_phase->setEnabled(true);
    ic->wave_type = "SQ";
}

