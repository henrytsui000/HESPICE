#ifndef SIMDIALOG_H
#define SIMDIALOG_H

#include <QDialog>

namespace Ui {
class Simdialog;
}

class Simdialog : public QDialog
{
    Q_OBJECT

public:
    explicit Simdialog(QWidget *parent = nullptr);
    ~Simdialog();

private:
    Ui::Simdialog *ui;
};

#endif // SIMDIALOG_H
