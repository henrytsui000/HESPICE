/********************************************************************************
** Form generated from reading UI file 'simu_time.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMU_TIME_H
#define UI_SIMU_TIME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_simu_time
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *simu_time)
    {
        if (simu_time->objectName().isEmpty())
            simu_time->setObjectName(QString::fromUtf8("simu_time"));
        simu_time->resize(400, 300);
        lineEdit = new QLineEdit(simu_time);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 120, 121, 20));
        pushButton = new QPushButton(simu_time);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 120, 75, 23));
        label = new QLabel(simu_time);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 60, 241, 16));

        retranslateUi(simu_time);

        QMetaObject::connectSlotsByName(simu_time);
    } // setupUi

    void retranslateUi(QDialog *simu_time)
    {
        simu_time->setWindowTitle(QCoreApplication::translate("simu_time", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("simu_time", "OK", nullptr));
        label->setText(QCoreApplication::translate("simu_time", "Total Simulation time?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class simu_time: public Ui_simu_time {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMU_TIME_H
