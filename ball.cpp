#include "ball.h"
#include "controller.h"

Ball* Ball::clicked;
QPoint Ball::startDragPos;
QPoint Ball::mouseDownOffset;

Ball::Ball(int n, QPoint p, QWidget* pr, QPair<int,int> i)
{

  setParent(pr);
  number = n;
  pos = p;
  index = i;

}

void Ball::setImage(){

     if(number == 30){
         QPixmap image = QPixmap::fromImage(QImage(":/images/trans.jpg"));
         setPixmap(image);
     }else{
         QPixmap image = QPixmap::fromImage(QImage(":/images/ball"+QString::number(number)+".png"));
         setPixmap(image);
     }
     this->move(pos);
     raise();
     show();
}

void Ball::mousePressEvent(QMouseEvent* ev){
    if(ev->button() == Qt::LeftButton){
        startDragPos = pos;
        mouseDownOffset = pos - ev->globalPos();
    }
}
void Ball::mouseMoveEvent(QMouseEvent* ev){
            if(number!=30){
                clicked = this;
                QPoint point = ev->globalPos() + mouseDownOffset;
                clicked->move(point);
                clicked->raise();
            }

}

void Ball::mouseReleaseEvent(QMouseEvent* ev){
    if(ev->buttons()) return;
    if(ev->x() >=10 || ev->y() >= 10){
      Controller::dragMove(ev);
    }else {
        clicked = NULL;
    }
}
