#ifndef SIMU_TIME_H
#define SIMU_TIME_H

#include <QDialog>
#include <QMap>
#include <mainwindow.h>
namespace Ui {
class simu_time;
}

class simu_time : public QDialog
{
    Q_OBJECT

public:
    explicit simu_time(QWidget *parent = nullptr);
    double Stime;
    ~simu_time();
    MainWindow* w;

private slots:
    void on_pushButton_clicked();

private:
    Ui::simu_time *ui;
    QMap<QChar, double> mp;
};

#endif // SIMU_TIME_H
