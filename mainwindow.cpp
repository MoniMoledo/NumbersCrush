#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "phase.h"
#include "aboutdialog.h"
#include "helpdialog.h"
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Numbers Crush");
    ui->label->setPixmap(QPixmap::fromImage(QImage(":/images/menu.jpg")));
    setWindowIcon(QIcon(QPixmap::fromImage(QImage(":/images/icon.png"))));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Phase * w = new Phase(this,1);
    w->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    Phase * w = new Phase(this,2);
    w->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    Phase * w = new Phase(this,3);
    w->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    Phase * w = new Phase(this,4);
    w->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    Phase * w = new Phase(this,5);
    w->show();
}

void MainWindow::on_action_About_triggered()
{
    AboutDialog *aDialog = new AboutDialog(this);
    aDialog->show();
}

void MainWindow::on_action_How_to_Play_triggered()
{
    HelpDialog *hDialog = new HelpDialog(this);
    hDialog->show();
}
