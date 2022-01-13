/********************************************************************************
** Form generated from reading UI file 'simu_freq.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMU_FREQ_H
#define UI_SIMU_FREQ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Simu_freq
{
public:
    QLabel *label;
    QLineEdit *lineEdit_l;
    QLineEdit *lineEdit_h;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Simu_freq)
    {
        if (Simu_freq->objectName().isEmpty())
            Simu_freq->setObjectName(QString::fromUtf8("Simu_freq"));
        Simu_freq->resize(403, 269);
        label = new QLabel(Simu_freq);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 70, 131, 31));
        lineEdit_l = new QLineEdit(Simu_freq);
        lineEdit_l->setObjectName(QString::fromUtf8("lineEdit_l"));
        lineEdit_l->setGeometry(QRect(40, 120, 91, 20));
        lineEdit_h = new QLineEdit(Simu_freq);
        lineEdit_h->setObjectName(QString::fromUtf8("lineEdit_h"));
        lineEdit_h->setGeometry(QRect(160, 120, 91, 20));
        label_2 = new QLabel(Simu_freq);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 120, 16, 21));
        label_3 = new QLabel(Simu_freq);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(260, 120, 21, 16));
        pushButton = new QPushButton(Simu_freq);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(300, 90, 75, 23));
        pushButton_2 = new QPushButton(Simu_freq);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 130, 75, 23));

        retranslateUi(Simu_freq);

        QMetaObject::connectSlotsByName(Simu_freq);
    } // setupUi

    void retranslateUi(QDialog *Simu_freq)
    {
        Simu_freq->setWindowTitle(QCoreApplication::translate("Simu_freq", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Simu_freq", "Enter range of frequency", nullptr));
        label_2->setText(QCoreApplication::translate("Simu_freq", "~", nullptr));
        label_3->setText(QCoreApplication::translate("Simu_freq", "1/s", nullptr));
        pushButton->setText(QCoreApplication::translate("Simu_freq", "OK", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Simu_freq", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Simu_freq: public Ui_Simu_freq {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMU_FREQ_H
