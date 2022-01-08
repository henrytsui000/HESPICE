#ifndef SETSOURCEDIALOG_H
#define SETSOURCEDIALOG_H

#include <QDialog>
#include <ic.h>

class IC;
namespace Ui {
class Setsourcedialog;
}

class Setsourcedialog : public QDialog
{
    Q_OBJECT

public:
    explicit Setsourcedialog(QWidget *parent = nullptr);
    ~Setsourcedialog();
    void initialization(IC *ic, int index);
    double chg(QString);
private slots:
    void on_pushButton_OK_clicked();

    void on_pushButton_Cancel_clicked();

    void on_radioButton_DC_clicked();

    void on_radioButton_AC_clicked();

    void on_radioButton_SQ_clicked();

private:
    Ui::Setsourcedialog *ui;
    IC *ic;
    int index;
    QMap<QChar, double> mp;
    friend class Circuit;
};

#endif // SETSOURCEDIALOG_H
