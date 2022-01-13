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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Sweep
{
public:
    QGraphicsView *graphicsView;
    QPushButton *Show;
    QPushButton *Cursor;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

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
        label_5 = new QLabel(Sweep);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(980, 170, 71, 16));
        label_2 = new QLabel(Sweep);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(910, 170, 47, 12));
        label_3 = new QLabel(Sweep);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(910, 190, 47, 12));
        label_4 = new QLabel(Sweep);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(980, 190, 71, 16));

        retranslateUi(Sweep);

        QMetaObject::connectSlotsByName(Sweep);
    } // setupUi

    void retranslateUi(QDialog *Sweep)
    {
        Sweep->setWindowTitle(QCoreApplication::translate("Sweep", "Dialog", nullptr));
        Show->setText(QCoreApplication::translate("Sweep", "SHOW", nullptr));
        Cursor->setText(QCoreApplication::translate("Sweep", "Cursor", nullptr));
        label_5->setText(QCoreApplication::translate("Sweep", "0", nullptr));
        label_2->setText(QCoreApplication::translate("Sweep", "V:", nullptr));
        label_3->setText(QCoreApplication::translate("Sweep", "freq:", nullptr));
        label_4->setText(QCoreApplication::translate("Sweep", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sweep: public Ui_Sweep {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWEEP_H
