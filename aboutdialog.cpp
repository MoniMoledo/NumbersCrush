#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(QPixmap::fromImage(QImage(":/images/info.png"))));
    setWindowTitle("About");
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
