#ifndef SPICE_H
#define SPICE_H

#include <QObject>
#include "mainwindow.h"
#include "QMainWindow"
#include <ui_mainwindow.h>
#include "circuit.h"
#include "ic.h"

class Spice
{
public:
    Spice(MainWindow*);
    ~Spice();
private:
    QMainWindow *mainwindow;
    Circuit *circuit;
private slots:
    void add_R();
    void add_L();
    void add_C();
    void add_V();
    void add_I();
    void add_GND();
};

#endif // SPICE_H
