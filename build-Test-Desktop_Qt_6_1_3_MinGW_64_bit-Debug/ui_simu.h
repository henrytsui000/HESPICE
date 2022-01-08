/********************************************************************************
** Form generated from reading UI file 'simu.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMU_H
#define UI_SIMU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <scope.h>

QT_BEGIN_NAMESPACE

class Ui_Simu
{
public:
    QPushButton *pushButton;
    Scope *graphicsView;

    void setupUi(QWidget *Simu)
    {
        if (Simu->objectName().isEmpty())
            Simu->setObjectName(QString::fromUtf8("Simu"));
        Simu->resize(732, 372);
        pushButton = new QPushButton(Simu);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(580, 110, 75, 23));
        graphicsView = new Scope(Simu);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 10, 461, 311));

        retranslateUi(Simu);

        QMetaObject::connectSlotsByName(Simu);
    } // setupUi

    void retranslateUi(QWidget *Simu)
    {
        Simu->setWindowTitle(QCoreApplication::translate("Simu", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Simu", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Simu: public Ui_Simu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMU_H
