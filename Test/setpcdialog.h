#ifndef SETPCDIALOG_H
#define SETPCDIALOG_H

#include <QDialog>
#include <ic.h>

class IC;
namespace Ui {
class Setpcdialog;
}

class Setpcdialog : public QDialog
{
    Q_OBJECT

public:
    explicit Setpcdialog(QWidget *parent = nullptr);
    ~Setpcdialog();
    void initialization(IC *ic, int index);
    double chg(QString);
private slots:
    void on_pushButton_ok_clicked();
    void on_pushButton_cancel_clicked();
private:
    Ui::Setpcdialog *ui;
    IC *ic;
    int index;
    friend class Circuit;
    QMap<QChar, double> mp;
};

#endif // SETPCDIALOG_H
