#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QMouseEvent>
#include <QResizeEvent>
#include <QToolBar>
#include <simu.h>
#include "help.h"
#include <QKeyEvent>
#include <QFileDialog>

#include "wave.h"
#include "sweep.h"
class Help;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void set_all_unchecked(void);
private slots:
    void on_actionR_triggered();
    void on_actionL_triggered();
    void on_actionC_triggered();
    void on_actionV_triggered();
    void on_actionI_triggered();
    void on_actionGND_triggered();
    void on_actionCUT_triggered();
    void on_actionMOVE_triggered();
    void on_actionWIRE_triggered();
    void on_actionBUILD_triggered();
    void on_actionWAVE_triggered();
    void on_actionWAVE_2();
    void on_actionZOOM_IN_triggered();
    void on_actionZOOM_OUT_triggered();
    friend class simu_time;
    friend class Circuit;
    void on_actionHELP_triggered();
    void on_actionCLEAR_triggered();
    void on_actionIMAGE_triggered();
    void on_actionSAVE_triggered();

    void on_actionSWEEP_triggered();

    void on_actionOPEN_triggered();

private:
    Ui::MainWindow *ui;
//    Simdialog *simdialog;
    Simu *sIMu;
//    Wave *wc;
    double Stime;
    void resizeEvent(QResizeEvent *event) override;
};
#endif // MAINWINDOW_H
