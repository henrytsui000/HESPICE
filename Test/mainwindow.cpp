#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "simu_time.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsview->w=this;
    ui->actionWAVE->setEnabled(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionR_triggered()
{
    ui->graphicsview->end_last();
    ui->graphicsview->set_op("R","ADD");
    set_all_unchecked();
    ui->actionR->setChecked(true);
}

void MainWindow::on_actionL_triggered()
{
    ui->graphicsview->end_last();
    ui->graphicsview->set_op("L","ADD");
    set_all_unchecked();
    ui->actionL->setChecked(true);
}

void MainWindow::on_actionC_triggered()
{
    ui->graphicsview->end_last();
    ui->graphicsview->set_op("C","ADD");
    set_all_unchecked();
    ui->actionC->setChecked(true);
}

void MainWindow::on_actionV_triggered()
{
    ui->graphicsview->end_last();
    ui->graphicsview->set_op("V","ADD");
    set_all_unchecked();
    ui->actionV->setChecked(true);
}

void MainWindow::on_actionI_triggered()
{
    ui->graphicsview->end_last();
    ui->graphicsview->set_op("I","ADD");
    set_all_unchecked();
    ui->actionI->setChecked(true);
}

void MainWindow::on_actionGND_triggered()
{
    ui->graphicsview->end_last();
    ui->graphicsview->set_op("G","ADD");
    set_all_unchecked();
    ui->actionGND->setChecked(true);
}

void MainWindow::on_actionCUT_triggered()
{
    ui->graphicsview->end_last();
    ui->graphicsview->set_op("NONE","CUT");
    set_all_unchecked();
    ui->actionCUT->setChecked(true);
}

void MainWindow::on_actionMOVE_triggered()
{
    ui->graphicsview->end_last();
    ui->graphicsview->set_op("NONE","MOVE");
    set_all_unchecked();
    ui->actionMOVE->setChecked(true);
}
void MainWindow::on_actionWIRE_triggered()
{
    ui->graphicsview->end_last();
    ui->graphicsview->set_op("W","ADD");
    set_all_unchecked();
    ui->actionWIRE->setChecked(true);
}

void MainWindow::set_all_unchecked(){
    ui->actionR->setChecked(false);
    ui->actionL->setChecked(false);
    ui->actionC->setChecked(false);
    ui->actionV->setChecked(false);
    ui->actionI->setChecked(false);
    ui->actionGND->setChecked(false);
    ui->actionMOVE->setChecked(false);
    ui->actionCUT->setChecked(false);
    ui->actionWIRE->setChecked(false);
}

void MainWindow::on_actionBUILD_triggered()
{
    ui->graphicsview->end_last();
    QString str = ui->graphicsview->check_connection();
    if(ui->graphicsview->is_connected){
        ui->actionWAVE->setEnabled(true);
        simu_time *st = new simu_time();
        st->w = this;
        st->show();
        qDebug() << "AF" << Stime;
    } else{
        ui->actionWAVE->setEnabled(false);
        QMessageBox::critical(this,"Failed", str);
    }
}


void MainWindow::on_actionWAVE_triggered() {
      ui->graphicsview->end_last();
      ui->graphicsview->run();
      Wave *wa = new Wave();
      wa->circuit = ui->graphicsview;
      wa->Stime = Stime;
      wa->show();
      ui->graphicsview->wave = wa;
      ui->graphicsview->set_op("NONE","WAVE");
      ui->actionWAVE->setEnabled(false);
}


void MainWindow::on_actionZOOM_IN_triggered()
{
    ui->graphicsview->scale_x*=1.15;
    ui->graphicsview->scale_y*=1.15;
    ui->graphicsview->scale(1.15,1.15);
}


void MainWindow::on_actionZOOM_OUT_triggered()
{
    ui->graphicsview->scale_x/=1.15;
    ui->graphicsview->scale_y/=1.15;
    ui->graphicsview->scale(1/1.15,1/1.15);
}

void MainWindow::resizeEvent(QResizeEvent *event){
    ui->graphicsview->setFixedSize(event->size());
}


void MainWindow::on_actionHELP_triggered()
{
    ui->graphicsview->end_last();
    help *Help = new help();
    Help->show();
}

void MainWindow::on_actionCLEAR_triggered()
{
    ui->graphicsview->end_last();
    ui->graphicsview->set_op("NONE","CLEAR");
    set_all_unchecked();
}


void MainWindow::on_actionIMAGE_triggered()
{
    ui->graphicsview->end_last();
    ui->graphicsview->set_op("NONE", "IMAGE");
    set_all_unchecked();
}


void MainWindow::on_actionSAVE_triggered()
{
    ui->graphicsview->end_last();
    ui->graphicsview->set_op("NONE","SAVE");
    set_all_unchecked();
}


void MainWindow::on_actionSWEEP_triggered()
{
    ui->graphicsview->end_last();
    ui->graphicsview->set_op("NONE","SWEEP");
    ui->graphicsview->sweep();
    Sweep *sw = new Sweep();
    sw->circuit = ui->graphicsview;
    sw->show();
    ui->graphicsview->swp = sw;
    ui->actionWAVE->setEnabled(false);
}


void MainWindow::on_actionOPEN_triggered()
{
    ui->graphicsview->end_last();
    ui->graphicsview->set_op("NONE","OPEN");
    set_all_unchecked();
}

