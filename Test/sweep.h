#ifndef SWEEP_H
#define SWEEP_H

#include <QDialog>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QVector>
#include <QLabel>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QButtonGroup>
#include "circuit.h"


class Circuit;
namespace Ui {
class Sweep;
}

class Sweep : public QDialog
{
    Q_OBJECT

public:
    explicit Sweep(QWidget *parent = nullptr);
    ~Sweep();
    Circuit* circuit;

    friend class Circuit;
private:
    Ui::Sweep *ui;
};

#endif // SWEEP_H
