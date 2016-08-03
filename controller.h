#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "map.h"
#include <QMouseEvent>
#include <QList>

class Controller :QWidget
{
private:
    static Map* m;
    static QWidget* phase;

public:
    Controller(QWidget* p);
    static void checkWin();
    static QList<Ball*> rule();
    static void crush();
    static QPoint getPos(QPoint p, double x, double y);
    static void dragMove(QMouseEvent* ev);
    static void fill(QWidget* parent,QWidget* mlb,QWidget* slb, int level, QWidget* phase);
    static void updateMoves();
    static int moves;
    static int score;
    static int level;
    static QLabel* mLabel;
    static QLabel* sLabel;
};

#endif // CONTROLLER_H
