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
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Sweep
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton;

    void setupUi(QDialog *Sweep)
    {
        if (Sweep->objectName().isEmpty())
            Sweep->setObjectName(QString::fromUtf8("Sweep"));
        Sweep->resize(400, 300);
        buttonBox = new QDialogButtonBox(Sweep);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        pushButton = new QPushButton(Sweep);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 160, 75, 23));

        retranslateUi(Sweep);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Sweep, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Sweep, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Sweep);
    } // setupUi

    void retranslateUi(QDialog *Sweep)
    {
        Sweep->setWindowTitle(QCoreApplication::translate("Sweep", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Sweep", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sweep: public Ui_Sweep {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWEEP_H
