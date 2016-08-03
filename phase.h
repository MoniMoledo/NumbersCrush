#ifndef PHASE_H
#define PHASE_H

#include <QMainWindow>
#include "controller.h"

namespace Ui {
class Phase;
}

class Phase : public QMainWindow
{
    Q_OBJECT

public:
    explicit Phase(QWidget *parent = 0, int level=1);
    ~Phase();
    friend class Controller;

private slots:
    void on_actionMenu_triggered();

private:
    Ui::Phase *ui;
};

#endif // PHASE_H
