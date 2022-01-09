/********************************************************************************
** Form generated from reading UI file 'setsourcedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETSOURCEDIALOG_H
#define UI_SETSOURCEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Setsourcedialog
{
public:
    QLabel *label_name;
    QLabel *label_freq;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_value;
    QPushButton *pushButton_OK;
    QPushButton *pushButton_Cancel;
    QLabel *label_value;
    QLineEdit *lineEdit_freq;
    QLabel *label_phase;
    QLineEdit *lineEdit_phase;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_DC;
    QRadioButton *radioButton_AC;
    QRadioButton *radioButton_SQ;
    QLabel *label_value_unit;
    QLabel *label_freq_unit;
    QLabel *label_value_4;

    void setupUi(QDialog *Setsourcedialog)
    {
        if (Setsourcedialog->objectName().isEmpty())
            Setsourcedialog->setObjectName(QString::fromUtf8("Setsourcedialog"));
        Setsourcedialog->resize(468, 360);
        label_name = new QLabel(Setsourcedialog);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(70, 40, 47, 12));
        label_freq = new QLabel(Setsourcedialog);
        label_freq->setObjectName(QString::fromUtf8("label_freq"));
        label_freq->setGeometry(QRect(90, 240, 71, 16));
        lineEdit_name = new QLineEdit(Setsourcedialog);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(160, 30, 113, 20));
        lineEdit_value = new QLineEdit(Setsourcedialog);
        lineEdit_value->setObjectName(QString::fromUtf8("lineEdit_value"));
        lineEdit_value->setGeometry(QRect(160, 190, 113, 20));
        pushButton_OK = new QPushButton(Setsourcedialog);
        pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));
        pushButton_OK->setGeometry(QRect(310, 80, 75, 23));
        pushButton_Cancel = new QPushButton(Setsourcedialog);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(310, 130, 75, 23));
        label_value = new QLabel(Setsourcedialog);
        label_value->setObjectName(QString::fromUtf8("label_value"));
        label_value->setGeometry(QRect(60, 190, 101, 16));
        lineEdit_freq = new QLineEdit(Setsourcedialog);
        lineEdit_freq->setObjectName(QString::fromUtf8("lineEdit_freq"));
        lineEdit_freq->setGeometry(QRect(160, 240, 113, 20));
        label_phase = new QLabel(Setsourcedialog);
        label_phase->setObjectName(QString::fromUtf8("label_phase"));
        label_phase->setGeometry(QRect(110, 290, 51, 16));
        lineEdit_phase = new QLineEdit(Setsourcedialog);
        lineEdit_phase->setObjectName(QString::fromUtf8("lineEdit_phase"));
        lineEdit_phase->setGeometry(QRect(160, 290, 113, 20));
        verticalLayoutWidget = new QWidget(Setsourcedialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(70, 80, 160, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_DC = new QRadioButton(verticalLayoutWidget);
        radioButton_DC->setObjectName(QString::fromUtf8("radioButton_DC"));

        verticalLayout->addWidget(radioButton_DC);

        radioButton_AC = new QRadioButton(verticalLayoutWidget);
        radioButton_AC->setObjectName(QString::fromUtf8("radioButton_AC"));

        verticalLayout->addWidget(radioButton_AC);

        radioButton_SQ = new QRadioButton(verticalLayoutWidget);
        radioButton_SQ->setObjectName(QString::fromUtf8("radioButton_SQ"));

        verticalLayout->addWidget(radioButton_SQ);

        label_value_unit = new QLabel(Setsourcedialog);
        label_value_unit->setObjectName(QString::fromUtf8("label_value_unit"));
        label_value_unit->setGeometry(QRect(290, 190, 31, 16));
        label_freq_unit = new QLabel(Setsourcedialog);
        label_freq_unit->setObjectName(QString::fromUtf8("label_freq_unit"));
        label_freq_unit->setGeometry(QRect(290, 240, 31, 16));
        label_value_4 = new QLabel(Setsourcedialog);
        label_value_4->setObjectName(QString::fromUtf8("label_value_4"));
        label_value_4->setGeometry(QRect(290, 290, 31, 16));

        retranslateUi(Setsourcedialog);

        QMetaObject::connectSlotsByName(Setsourcedialog);
    } // setupUi

    void retranslateUi(QDialog *Setsourcedialog)
    {
        Setsourcedialog->setWindowTitle(QCoreApplication::translate("Setsourcedialog", "Dialog", nullptr));
        label_name->setText(QCoreApplication::translate("Setsourcedialog", "Name", nullptr));
        label_freq->setText(QCoreApplication::translate("Setsourcedialog", "frequency", nullptr));
        pushButton_OK->setText(QCoreApplication::translate("Setsourcedialog", "OK", nullptr));
        pushButton_Cancel->setText(QCoreApplication::translate("Setsourcedialog", "Cancel", nullptr));
        label_value->setText(QCoreApplication::translate("Setsourcedialog", "amplitude/value", nullptr));
        label_phase->setText(QCoreApplication::translate("Setsourcedialog", "phase", nullptr));
        radioButton_DC->setText(QCoreApplication::translate("Setsourcedialog", "DC", nullptr));
        radioButton_AC->setText(QCoreApplication::translate("Setsourcedialog", "SINE", nullptr));
        radioButton_SQ->setText(QCoreApplication::translate("Setsourcedialog", "SQUARE", nullptr));
        label_value_unit->setText(QCoreApplication::translate("Setsourcedialog", "V/A", nullptr));
        label_freq_unit->setText(QCoreApplication::translate("Setsourcedialog", "1/s", nullptr));
        label_value_4->setText(QCoreApplication::translate("Setsourcedialog", "rad", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Setsourcedialog: public Ui_Setsourcedialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETSOURCEDIALOG_H
