/********************************************************************************
** Form generated from reading UI file 'setpcdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETPCDIALOG_H
#define UI_SETPCDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Setpcdialog
{
public:
    QPushButton *pushButton_ok;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_value;
    QLabel *label_name;
    QLabel *label_value;
    QPushButton *pushButton_cancel;
    QLabel *label_value_2;

    void setupUi(QDialog *Setpcdialog)
    {
        if (Setpcdialog->objectName().isEmpty())
            Setpcdialog->setObjectName(QString::fromUtf8("Setpcdialog"));
        Setpcdialog->resize(368, 183);
        pushButton_ok = new QPushButton(Setpcdialog);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(260, 60, 75, 23));
        lineEdit_name = new QLineEdit(Setpcdialog);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(80, 60, 101, 20));
        lineEdit_value = new QLineEdit(Setpcdialog);
        lineEdit_value->setObjectName(QString::fromUtf8("lineEdit_value"));
        lineEdit_value->setGeometry(QRect(80, 110, 101, 20));
        label_name = new QLabel(Setpcdialog);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(30, 60, 47, 12));
        label_value = new QLabel(Setpcdialog);
        label_value->setObjectName(QString::fromUtf8("label_value"));
        label_value->setGeometry(QRect(30, 110, 47, 12));
        pushButton_cancel = new QPushButton(Setpcdialog);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(260, 110, 75, 23));
        label_value_2 = new QLabel(Setpcdialog);
        label_value_2->setObjectName(QString::fromUtf8("label_value_2"));
        label_value_2->setGeometry(QRect(190, 110, 47, 21));

        retranslateUi(Setpcdialog);

        QMetaObject::connectSlotsByName(Setpcdialog);
    } // setupUi

    void retranslateUi(QDialog *Setpcdialog)
    {
        Setpcdialog->setWindowTitle(QCoreApplication::translate("Setpcdialog", "Dialog", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("Setpcdialog", "OK", nullptr));
        label_name->setText(QCoreApplication::translate("Setpcdialog", "Name", nullptr));
        label_value->setText(QCoreApplication::translate("Setpcdialog", "value", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("Setpcdialog", "Cancel", nullptr));
        label_value_2->setText(QCoreApplication::translate("Setpcdialog", "\316\251 / L / F", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Setpcdialog: public Ui_Setpcdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETPCDIALOG_H
