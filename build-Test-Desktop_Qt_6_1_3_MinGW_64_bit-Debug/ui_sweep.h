/********************************************************************************
** Form generated from reading UI file 'sweep.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SWEEP_H
#define UI_SWEEP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Sweep
{
public:
    QGraphicsView *graphicsView;
    QPushButton *Show;
    QPushButton *Cursor;

    void setupUi(QDialog *Sweep)
    {
        if (Sweep->objectName().isEmpty())
            Sweep->setObjectName(QString::fromUtf8("Sweep"));
        Sweep->resize(1062, 680);
        graphicsView = new QGraphicsView(Sweep);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(80, 10, 802, 602));
        Show = new QPushButton(Sweep);
        Show->setObjectName(QString::fromUtf8("Show"));
        Show->setGeometry(QRect(920, 50, 75, 23));
        Cursor = new QPushButton(Sweep);
        Cursor->setObjectName(QString::fromUtf8("Cursor"));
        Cursor->setGeometry(QRect(920, 100, 75, 23));
        Cursor->setCheckable(true);

        retranslateUi(Sweep);

        QMetaObject::connectSlotsByName(Sweep);
    } // setupUi

    void retranslateUi(QDialog *Sweep)
    {
        Sweep->setWindowTitle(QCoreApplication::translate("Sweep", "Dialog", nullptr));
        Show->setText(QCoreApplication::translate("Sweep", "SHOW", nullptr));
        Cursor->setText(QCoreApplication::translate("Sweep", "Cursor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sweep: public Ui_Sweep {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWEEP_H
