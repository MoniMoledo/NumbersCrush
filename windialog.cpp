#include "windialog.h"
#include "ui_windialog.h"
#include <QMainWindow>

WinDialog::WinDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WinDialog)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(QPixmap::fromImage(QImage(":/images/win.png"))));
    setWindowTitle("Victory!");
}

WinDialog::~WinDialog()
{
    delete ui;
}

void WinDialog::on_pushButton_clicked()
{
   parentWidget()->parentWidget()->show();
   parentWidget()->close();
   this->close();
}
