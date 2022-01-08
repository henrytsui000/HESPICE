/********************************************************************************
** Form generated from reading UI file 'help.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_help
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QDialog *help)
    {
        if (help->objectName().isEmpty())
            help->setObjectName(QString::fromUtf8("help"));
        help->resize(501, 401);
        textBrowser = new QTextBrowser(help);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 501, 401));

        retranslateUi(help);

        QMetaObject::connectSlotsByName(help);
    } // setupUi

    void retranslateUi(QDialog *help)
    {
        help->setWindowTitle(QCoreApplication::translate("help", "Dialog", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("help", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'PMingLiU'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505; background-color:#e4e6eb;\">\345\227\250\344\275\240\345\245\275 \344\275\240\346\234\203\346\214\211\346\210\221\357\274\214\344\270\200\345\256\232\346\230\257\345\233\240\347\202\272\344\275\240\351\234\200\350\246\201\345\271\253\345\212\251</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','s"
                        "ans-serif'; color:#050505; background-color:#e4e6eb;\">\344\275\206\346\230\257\346\210\221\345\277\205\351\240\210\345\205\210\350\207\252\346\210\221\344\273\213\347\264\271\357\274\214\342\200\234\344\273\226\351\246\231\346\226\231\342\200\235\357\274\214\347\202\272\344\273\200\351\272\274\346\230\257\344\273\226\351\246\231\346\226\231\345\221\242\357\274\237</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505; background-color:#e4e6eb;\">\345\233\240\347\202\272\346\210\221\346\230\257Henry \346\255\220\345\223\245\346\230\257Ethan \351\200\231\346\230\257SPICE</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505; background-color:"
                        "#e4e6eb;\">\346\211\200\344\273\245\351\200\231\345\260\261\346\230\257HESPICE\357\274\214\345\216\262\345\256\263\345\220\247</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505; background-color:#e4e6eb;\">\346\223\215\344\275\234\350\252\252\346\230\216\357\274\232</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px"
                        "; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505; background-color:#e4e6eb;\">\346\224\276\347\275\256\344\273\213\351\235\242</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505; background-color:#e4e6eb;\">\346\214\211O \346\210\226\346\230\257 \351\233\273\351\230\273\347\232\204\345\234\226\344\276\213 \345\217\257\344\273\245\345\217\253\345\207\272\346\224\276\347\275\256Resistance\344\273\213\351\235\242</span></p>\n"
"<p style=\" margin-"
                        "top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505; background-color:#e4e6eb;\">\346\214\211L \346\210\226\346\230\257 \351\233\273\346\204\237\347\232\204\345\234\226\344\276\213 \345\217\257\344\273\245\345\217\253\345\207\272\346\224\276\347\275\256Inductance\344\273\213\351\235\242</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505; background-color:#e4e6eb;\">\346\214\211C \346\210\226\346\230\257 \351\233\273\345\256\271\347\232\204\345\234\226\344\276\213 \345\217\257\344\273\245\345\217\253\345\207\272\346\224\276\347\275\256Capacitance\344\273\213\351\235\242</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-b"
                        "lock-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505; background-color:#e4e6eb;\">\346\214\211I \346\210\226\346\230\257 \351\233\273\345\243\223\347\232\204\345\234\226\344\276\213 \345\217\257\344\273\245\345\217\253\345\207\272\346\224\276\347\275\256Voltage Source\344\273\213\351\235\242</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505; background-color:#e4e6eb;\">\346\214\211V \346\210\226\346\230\257 \351\233\273\346\265\201\347\232\204\345\234\226\344\276\213 \345\217\257\344\273\245\345\217\253\345\207\272\346\224\276\347\275\256Current Source\344\273\213\351\235\242</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:"
                        "'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505; background-color:#e4e6eb;\">\346\214\211W \346\210\226\346\230\257 \351\233\273\347\267\232\347\232\204\345\234\226\344\276\213 \345\217\257\344\273\245\345\217\253\345\207\272Wire\344\273\213\351\235\242</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:"
                        "#050505; background-color:#e4e6eb;\">\346\224\276\345\244\247\351\217\241\351\241\257\345\276\256\351\217\241\345\211\207\346\230\257\344\273\243\350\241\250\345\260\207\351\233\273\350\267\257\350\256\212\345\244\247\346\210\226\347\270\256\345\260\217</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505; background-color:#e4e6eb;\">\345\211\252\345\210\200\345\211\207\346\230\257\345\217\257\344\273\245\345\210\252\351\231\244\351\233\273\347\267\232\346\210\226\345\205\203\344\273\266</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-righ"
                        "t:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505; background-color:#e4e6eb;\">\345\234\250\346\262\222\346\234\211\351\240\220\351\201\270\346\223\215\344\275\234\344\270\213\357\274\214\345\267\246\351\215\265\345\217\257\344\273\245\346\213\226\346\233\263\346\225\264\351\253\224\351\233\273\350\267\257</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505; background-color:#e4e6eb;\">\345\260\215\345\205\203\344\273\266\346\214\211\345\267\246\351\215\265\357\274\214\345\217"
                        "\257\344\273\245\342\200\234\346\223\215\344\275\234\342\200\235</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505; background-color:#e4e6eb;\">\345\260\215\345\205\203\344\273\266\346\214\211\345\217\263\351\215\265\357\274\214\345\217\257\344\273\245\350\252\277\346\225\264\345\217\203\346\225\270\346\210\226\346\230\257\345\217\226\346\266\210\346\224\276\347\275\256</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI Historic','Segoe UI','Helvetica','"
                        "Arial','sans-serif'; color:#050505; background-color:#e4e6eb;\">\347\267\250\350\255\257\344\273\213\351\235\242</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505; background-color:#e4e6eb;\">\346\214\211\344\270\213\345\273\272\346\247\213\345\234\226\347\244\272 \345\217\257\344\273\245\345\273\272\346\247\213\351\233\273\350\267\257</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505;"
                        " background-color:#e4e6eb;\">\346\214\211\344\270\213\346\263\242\345\275\242\345\234\226\347\244\272 \346\234\203\351\241\257\347\244\272SCOPE</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505; background-color:#e4e6eb;\">\345\260\215\350\246\201\350\247\200\345\257\237\347\232\204\351\233\273\347\267\232\345\200\221\346\214\211\345\267\246\351\215\265\357\274\214\345\206\215\346\214\211show\345\217\257\344\273\245\351\241\257\347\244\272\346\263\242\345\275\242</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-inden"
                        "t:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505; background-color:#e4e6eb;\">(auto scaled)</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505; background-color:#e4e6eb;\">\346\214\211\344\270\213Cursor\345\217\257\344\273\245\351\201\270\346\223\207\350\246\201\350\277\275\350\271\244\347\232\204\351\233\273\347\267\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI Hist"
                        "oric','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505; background-color:#e4e6eb;\">\345\234\250Graphics view\347\247\273\345\213\225\345\217\257\344\273\245\346\270\254\351\207\217\346\237\220\351\233\273\347\267\232\347\232\204\346\231\202\351\226\223-\351\233\273\345\243\223</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI Historic','Segoe UI','Helvetica','Arial','sans-serif'; color:#050505; background-color:#e4e6eb;\">\346\214\211\344\270\213\345\204\262\345\255\230\357\274\214\345\217\257\344\273\245\345\260\207\350\250\212\350\231\237\345\204\262\345\255\230\345\210\260\346\214\207\345\256\232\347\232\204\344\275\215\347\275"
                        "\256</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class help: public Ui_help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
