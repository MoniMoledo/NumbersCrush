#include "helpdialog.h"
#include "ui_helpdialog.h"

HelpDialog::HelpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpDialog)
{
    ui->setupUi(this);
    setWindowTitle("How To Play");
    setWindowIcon(QIcon(QPixmap::fromImage(QImage(":/images/help.png"))));
}

HelpDialog::~HelpDialog()
{
    delete ui;
}
