#ifndef BALL_H
#define BALL_H
#include <QLabel>
#include <QMouseEvent>
#include <QPair>

class Ball : QLabel
{
private:
    int number;
    QPoint pos;
    QPair<int,int> index;
    bool wasDragged();
    static Ball* clicked;
    static QPoint startDragPos;
    static QPoint mouseDownOffset;

   // void mouseGrabber(QMouseEvent * ev);
public:
    Ball(int n, QPoint p, QWidget* pr, QPair<int,int> index);
    void setImage();
    void mousePressEvent(QMouseEvent* ev);
    void mouseMoveEvent(QMouseEvent* ev);
    void mouseReleaseEvent(QMouseEvent* ev);
    friend class Controller;
    friend class Map;
};

#endif // BALL_H
