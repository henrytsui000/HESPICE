/********************************************************************************
** Form generated from reading UI file 'simdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMDIALOG_H
#define UI_SIMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <scope.h>

QT_BEGIN_NAMESPACE

class Ui_Simdialog
{
public:
    Scope *graphicsView;
    QPushButton *pushButton;

    void setupUi(QDialog *Simdialog)
    {
        if (Simdialog->objectName().isEmpty())
            Simdialog->setObjectName(QString::fromUtf8("Simdialog"));
        Simdialog->resize(627, 491);
        graphicsView = new Scope(Simdialog);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 401, 301));
        pushButton = new QPushButton(Simdialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 140, 75, 23));

        retranslateUi(Simdialog);

        QMetaObject::connectSlotsByName(Simdialog);
    } // setupUi

    void retranslateUi(QDialog *Simdialog)
    {
        Simdialog->setWindowTitle(QCoreApplication::translate("Simdialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Simdialog", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Simdialog: public Ui_Simdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMDIALOG_H
