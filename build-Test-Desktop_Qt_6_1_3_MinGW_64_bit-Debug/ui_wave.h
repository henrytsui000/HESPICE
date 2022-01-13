/********************************************************************************
** Form generated from reading UI file 'wave.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAVE_H
#define UI_WAVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <scope.h>

QT_BEGIN_NAMESPACE

class Ui_Wave
{
public:
    QPushButton *pushButton;
    Scope *graphicsView;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QComboBox *comboBox;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label;
    QLabel *label_2;
    QGroupBox *groupBox;

    void setupUi(QDialog *Wave)
    {
        if (Wave->objectName().isEmpty())
            Wave->setObjectName(QString::fromUtf8("Wave"));
        Wave->resize(1029, 652);
        pushButton = new QPushButton(Wave);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(930, 20, 75, 23));
        graphicsView = new Scope(Wave);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(80, 10, 802, 602));
        pushButton_2 = new QPushButton(Wave);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(930, 70, 75, 23));
        pushButton_3 = new QPushButton(Wave);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(930, 120, 75, 23));
        comboBox = new QComboBox(Wave);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(930, 150, 69, 22));
        label_6 = new QLabel(Wave);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(960, 180, 47, 12));
        label_7 = new QLabel(Wave);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(930, 180, 21, 16));
        label_8 = new QLabel(Wave);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(930, 200, 47, 12));
        label_9 = new QLabel(Wave);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(960, 200, 47, 12));
        label = new QLabel(Wave);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 300, 21, 16));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(Wave);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(930, 620, 21, 16));
        label_2->setFont(font);
        groupBox = new QGroupBox(Wave);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(890, 230, 120, 371));

        retranslateUi(Wave);

        QMetaObject::connectSlotsByName(Wave);
    } // setupUi

    void retranslateUi(QDialog *Wave)
    {
        Wave->setWindowTitle(QCoreApplication::translate("Wave", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Wave", "SHOW", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Wave", "SAVE", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Wave", "Cursor", nullptr));
        label_6->setText(QCoreApplication::translate("Wave", "0", nullptr));
        label_7->setText(QCoreApplication::translate("Wave", "V:", nullptr));
        label_8->setText(QCoreApplication::translate("Wave", "T", nullptr));
        label_9->setText(QCoreApplication::translate("Wave", "0", nullptr));
        label->setText(QCoreApplication::translate("Wave", "V", nullptr));
        label_2->setText(QCoreApplication::translate("Wave", "s", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Wave", "GroupBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Wave: public Ui_Wave {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAVE_H
