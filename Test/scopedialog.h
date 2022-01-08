#ifndef SCOPEDIALOG_H
#define SCOPEDIALOG_H

#include <QDialog>

namespace Ui {
class ScopeDialog;
}

class ScopeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScopeDialog(QWidget *parent = nullptr);
    ~ScopeDialog();

private:
    Ui::ScopeDialog *ui;
};

#endif // SCOPEDIALOG_H
