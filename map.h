#ifndef MAP_H
#define MAP_H
#include "ball.h"

class Map : QLabel
{
private:
    Ball* balls[9][9];
public:
    Map(QWidget* p);
    void placeBalls(int level);
    void setImage();
    void bMove(int fromR,int fromC,int toR,int toC);
    friend class Controller;
};

#endif // MAP_H
