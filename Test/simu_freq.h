#ifndef SIMU_FREQ_H
#define SIMU_FREQ_H

#include <QDialog>
#include <QMap>
#include <mainwindow.h>
class MainWindow;
namespace Ui {
class Simu_freq;
}

class Simu_freq : public QDialog
{
    Q_OBJECT

public:
    explicit Simu_freq(QWidget *parent = nullptr);
    double freq_l;
    double freq_h;
    ~Simu_freq();
    MainWindow* w;
private slots:
    void on_pushButton_clicked();

private:
    Ui::Simu_freq *ui;
    QMap<QChar, double> mp;
};

#endif // SIMU_FREQ_H
