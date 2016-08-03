#include "phase.h"
#include "ui_phase.h"

Phase::Phase(QWidget *parent, int level) :
    QMainWindow(parent),
    ui(new Ui::Phase)
{
    ui->setupUi(this);
    ui->label->setScaledContents(true);
    parent->hide();
    setWindowTitle("level "+QString::number(level));
    Controller::fill(ui->label,ui->textBrowser_2,ui->textBrowser, level, this);
    Controller::crush();
    Controller::updateMoves();
}

Phase::~Phase()
{
    delete ui;
}

void Phase::on_actionMenu_triggered()
{
    parentWidget()->show();
    this->close();
}
