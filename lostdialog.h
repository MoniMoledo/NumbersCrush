#ifndef LOSTDIALOG_H
#define LOSTDIALOG_H

#include <QDialog>

namespace Ui {
class LostDialog;
}

class LostDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LostDialog(QWidget *parent = 0,int level=1,QWidget *phase = 0);
    ~LostDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LostDialog *ui;
    int level;
    QWidget *phase;
};

#endif // LOSTDIALOG_H
