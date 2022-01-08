#ifndef SIMU_H
#define SIMU_H

#include <QWidget>

namespace Ui {
class Simu;
}

class Simu : public QWidget
{
    Q_OBJECT

public:
    explicit Simu(QWidget *parent = nullptr);
    ~Simu();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Simu *ui;
};

#endif // SIMU_H
