#include "controller.h"
#include "lostdialog.h"
#include "windialog.h"
 Map* Controller::m;
 int Controller::moves;
 int Controller::score;
 int Controller::level;
 QLabel* Controller::mLabel;
 QLabel* Controller::sLabel;
 QWidget* Controller::phase;

 Controller::Controller(QWidget* p)
{
  setParent(p);
}

void Controller::fill(QWidget* parent, QWidget* mlb, QWidget* slb, int level,QWidget* ph){
    m = new Map(parent);
    m->setImage();
    m->placeBalls(level);
    moves = 25 + level*21;
    score = 0;
    mLabel= new QLabel(mlb);
    sLabel = new QLabel(slb);
    phase = ph;
    Controller::level = level;
}

void Controller::updateMoves(){
    mLabel->setText("Moves: "+QString::number(moves)+ "  ");
    mLabel->setAlignment(Qt::AlignCenter);
    sLabel->setText("Score: "+QString::number(score+(moves*10))+ "      ");
    if(moves ==0){
        LostDialog * w = new LostDialog(phase->parentWidget(),level,phase);
        w->show();
    }
}

QList<Ball*> Controller::rule(){
   QList<Ball*> balls;
   for(int r =0; r<9;r++){
       for(int c =0; c<9;c++){
           int n = m->balls[r][c]->number;
           int count = 0;
           for(int i = r; i < 9; i++){
               if(m->balls[i][c]->number == n){
                  balls.append(m->balls[i][c]);
                  count++;
               }else{
                   break;
               }
           }
           if(count == n){
               return balls;
           }else{
               balls.clear();
           }
           count = 0;
           for(int j = c; j< 9; j++){
               if(m->balls[r][j]->number == n){
                  balls.append(m->balls[r][j]);
                  count++;
               }else{
                   break;
               }
           }
           if(count == n){
               return balls;
           }else{
               balls.clear();
           }
       }
   }
   return balls;
}

void Controller::crush(){
    QList<Ball*> balls = rule();
    while(!balls.empty()){
       while(!balls.empty()){
          score += balls.last()->number;
          balls.last()->number = 30;
          balls.last()->setImage();
          for(int i = balls.last()->index.first; i >0; i--){
              int c = balls.last()->index.second;
              Ball* fromB = m->balls[i][c];
              Ball* toB = m->balls[i-1][c];
              m->bMove(fromB->index.first,fromB->index.second,toB->index.first,toB->index.second);
          }
          balls.removeLast();

      }
    balls = rule();
    }
}

QPoint Controller::getPos(QPoint p, double x, double y){
    if( abs(x)<=20){
        if(y>=0){
           return QPoint(p.x(),p.y()-41);
        }else{
          return QPoint(p.x(),p.y()+41);
        }
    }else{
        if(x >=0){
          return QPoint(p.x()-43,p.y());
        }else{
            return QPoint(p.x()+43,p.y());
          }
    }
}

void Controller::checkWin(){
    bool win = true;
    for(int i = 0; i<9; i++){
        if(m->balls[8][i]->number != 30){
            win = false;
        }
    }
    if(win){
        WinDialog * w = new WinDialog(phase);
        w->show();
    }
}

void Controller::dragMove(QMouseEvent *ev)
{
  Ball* clicked = Ball::clicked;
  if(clicked){
      QPoint posDroped = ev->globalPos() + Ball::mouseDownOffset;
      double x = clicked->pos.x() - posDroped.x();
      double y = clicked->pos.y() - posDroped.y();
      double absX = abs(x);
      double absY = abs(y);
      if(posDroped.x() <=350 && posDroped.x() >= 0 && posDroped.y() <=335 && posDroped.y() >= 0 ){
          if(( absX <= 43 &&  absY >= 20 ) ||
                  (absY <= 43 && absX >= 20)){
             QPoint rPosDropped = Controller::getPos(clicked->pos,x,y);
              int i = (rPosDropped.x()-4)/43;
              int j = (rPosDropped.y()-4)/41;
              int newI = clicked->index.second;
              int newJ = clicked->index.first;
                  m->bMove(newJ,newI,j,i);
                  //drop balls where there is space under it.
                  int t = newJ-1;
                  while(t<8 && t>=0 && m->balls[t+1][newI]->number == 30 ){
                          Ball* fromB = m->balls[t][newI];
                          Ball* toB = m->balls[t+1][newI];
                          m->bMove(fromB->index.first,fromB->index.second,toB->index.first,toB->index.second);
                          t--;
                  }
                  //drop the ball that was released where there was space under it.
                  int l = j;
                  while(l<8 && m->balls[l+1][i]->number == 30 ){
                          Ball* fromB = m->balls[l][i];
                          Ball* toB = m->balls[l+1][i];
                          m->bMove(fromB->index.first,fromB->index.second,toB->index.first,toB->index.second);
                          l++;
                  }
                      moves--;
                      Controller::crush();
                      checkWin();
                      updateMoves();


          }else{
              clicked->move(Ball::startDragPos);
          }
      }else{
          clicked->move(Ball::startDragPos);
      }
      Ball::clicked = NULL;
  }
}
