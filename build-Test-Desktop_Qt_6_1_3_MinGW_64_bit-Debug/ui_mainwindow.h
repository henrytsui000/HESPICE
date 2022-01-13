/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <circuit.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionR;
    QAction *actionL;
    QAction *actionC;
    QAction *actionV;
    QAction *actionI;
    QAction *actionGND;
    QAction *actionCUT;
    QAction *actionMOVE;
    QAction *actionWIRE;
    QAction *actionBUILD;
    QAction *actionWAVE;
    QAction *actionZOOM_IN;
    QAction *actionZOOM_OUT;
    QAction *actionHELP;
    QAction *actionCLEAR;
    QAction *actionIMAGE;
    QAction *actionSAVE;
    QAction *actionSWEEP;
    QAction *actionOPEN;
    QWidget *centralwidget;
    Circuit *graphicsview;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 720);
        actionR = new QAction(MainWindow);
        actionR->setObjectName(QString::fromUtf8("actionR"));
        actionR->setCheckable(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pre/R.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionR->setIcon(icon);
        actionL = new QAction(MainWindow);
        actionL->setObjectName(QString::fromUtf8("actionL"));
        actionL->setCheckable(true);
        actionL->setChecked(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/pre/L.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionL->setIcon(icon1);
        actionC = new QAction(MainWindow);
        actionC->setObjectName(QString::fromUtf8("actionC"));
        actionC->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/pre/C.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionC->setIcon(icon2);
        actionV = new QAction(MainWindow);
        actionV->setObjectName(QString::fromUtf8("actionV"));
        actionV->setCheckable(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/pre/V.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionV->setIcon(icon3);
        actionI = new QAction(MainWindow);
        actionI->setObjectName(QString::fromUtf8("actionI"));
        actionI->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/pre/I.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionI->setIcon(icon4);
        actionGND = new QAction(MainWindow);
        actionGND->setObjectName(QString::fromUtf8("actionGND"));
        actionGND->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/pre/GND.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGND->setIcon(icon5);
        actionCUT = new QAction(MainWindow);
        actionCUT->setObjectName(QString::fromUtf8("actionCUT"));
        actionCUT->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/pre/CUT.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCUT->setIcon(icon6);
        actionMOVE = new QAction(MainWindow);
        actionMOVE->setObjectName(QString::fromUtf8("actionMOVE"));
        actionMOVE->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/pre/MOVE.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMOVE->setIcon(icon7);
        actionWIRE = new QAction(MainWindow);
        actionWIRE->setObjectName(QString::fromUtf8("actionWIRE"));
        actionWIRE->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/pre/WIRE.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionWIRE->setIcon(icon8);
        actionBUILD = new QAction(MainWindow);
        actionBUILD->setObjectName(QString::fromUtf8("actionBUILD"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/pre/BUILD.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBUILD->setIcon(icon9);
        actionWAVE = new QAction(MainWindow);
        actionWAVE->setObjectName(QString::fromUtf8("actionWAVE"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/pre/WAVE.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon10.addFile(QString::fromUtf8(":/pre/WAVE2.png"), QSize(), QIcon::Disabled, QIcon::Off);
        actionWAVE->setIcon(icon10);
        actionZOOM_IN = new QAction(MainWindow);
        actionZOOM_IN->setObjectName(QString::fromUtf8("actionZOOM_IN"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/pre/ZOOM_IN.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZOOM_IN->setIcon(icon11);
        actionZOOM_OUT = new QAction(MainWindow);
        actionZOOM_OUT->setObjectName(QString::fromUtf8("actionZOOM_OUT"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/pre/ZOOM_OUT.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZOOM_OUT->setIcon(icon12);
        actionHELP = new QAction(MainWindow);
        actionHELP->setObjectName(QString::fromUtf8("actionHELP"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/pre/HELP.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHELP->setIcon(icon13);
        actionCLEAR = new QAction(MainWindow);
        actionCLEAR->setObjectName(QString::fromUtf8("actionCLEAR"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/pre/CLEAR.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCLEAR->setIcon(icon14);
        actionIMAGE = new QAction(MainWindow);
        actionIMAGE->setObjectName(QString::fromUtf8("actionIMAGE"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/pre/IMAGE.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionIMAGE->setIcon(icon15);
        actionSAVE = new QAction(MainWindow);
        actionSAVE->setObjectName(QString::fromUtf8("actionSAVE"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/pre/SAVE.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSAVE->setIcon(icon16);
        actionSWEEP = new QAction(MainWindow);
        actionSWEEP->setObjectName(QString::fromUtf8("actionSWEEP"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/pre/SWEEP.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSWEEP->setIcon(icon17);
        actionOPEN = new QAction(MainWindow);
        actionOPEN->setObjectName(QString::fromUtf8("actionOPEN"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/pre/OPEN.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOPEN->setIcon(icon18);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsview = new Circuit(centralwidget);
        graphicsview->setObjectName(QString::fromUtf8("graphicsview"));
        graphicsview->setGeometry(QRect(0, 0, 1200, 720));
        graphicsview->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsview->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setIconSize(QSize(36, 36));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionOPEN);
        toolBar->addAction(actionSAVE);
        toolBar->addAction(actionR);
        toolBar->addAction(actionL);
        toolBar->addAction(actionC);
        toolBar->addAction(actionV);
        toolBar->addAction(actionI);
        toolBar->addAction(actionGND);
        toolBar->addSeparator();
        toolBar->addSeparator();
        toolBar->addAction(actionWIRE);
        toolBar->addAction(actionCUT);
        toolBar->addAction(actionMOVE);
        toolBar->addAction(actionZOOM_IN);
        toolBar->addAction(actionZOOM_OUT);
        toolBar->addAction(actionCLEAR);
        toolBar->addSeparator();
        toolBar->addSeparator();
        toolBar->addAction(actionBUILD);
        toolBar->addAction(actionWAVE);
        toolBar->addAction(actionSWEEP);
        toolBar->addAction(actionIMAGE);
        toolBar->addAction(actionHELP);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionR->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        actionL->setText(QCoreApplication::translate("MainWindow", "L", nullptr));
        actionC->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        actionV->setText(QCoreApplication::translate("MainWindow", "V", nullptr));
        actionI->setText(QCoreApplication::translate("MainWindow", "I", nullptr));
        actionGND->setText(QCoreApplication::translate("MainWindow", "GND", nullptr));
        actionCUT->setText(QCoreApplication::translate("MainWindow", "CUT", nullptr));
        actionMOVE->setText(QCoreApplication::translate("MainWindow", "MOVE", nullptr));
        actionWIRE->setText(QCoreApplication::translate("MainWindow", "WIRE", nullptr));
        actionBUILD->setText(QCoreApplication::translate("MainWindow", "BUILD", nullptr));
        actionWAVE->setText(QCoreApplication::translate("MainWindow", "WAVE", nullptr));
        actionZOOM_IN->setText(QCoreApplication::translate("MainWindow", "ZOOM_IN", nullptr));
        actionZOOM_OUT->setText(QCoreApplication::translate("MainWindow", "ZOOM_OUT", nullptr));
        actionHELP->setText(QCoreApplication::translate("MainWindow", "HELP", nullptr));
        actionCLEAR->setText(QCoreApplication::translate("MainWindow", "CLEAR", nullptr));
        actionIMAGE->setText(QCoreApplication::translate("MainWindow", "IMAGE", nullptr));
        actionSAVE->setText(QCoreApplication::translate("MainWindow", "SAVE", nullptr));
        actionSWEEP->setText(QCoreApplication::translate("MainWindow", "SWEEP", nullptr));
        actionOPEN->setText(QCoreApplication::translate("MainWindow", "OPEN", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
