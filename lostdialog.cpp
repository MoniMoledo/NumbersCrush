#include "lostdialog.h"
#include "ui_lostdialog.h"
#include "phase.h"

LostDialog::LostDialog(QWidget *parent, int lvl, QWidget* ph) :
    QDialog(parent),
    ui(new Ui::LostDialog)
{
    ui->setupUi(this);
    setWindowTitle("Try again");
    level = lvl;
    phase = ph;
}

LostDialog::~LostDialog()
{
    delete ui;
}

void LostDialog::on_pushButton_clicked()
{
    Phase * w = new Phase(phase->parentWidget(),level);
    this->close();
    phase->close();
    w->show();

}
