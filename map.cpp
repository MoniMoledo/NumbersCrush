#include "map.h"
#include <QTime>

Map::Map(QWidget* p)
{
  setParent(p);
}


void Map::setImage(){
    this->setScaledContents(true);
    this->resize(this->parentWidget()->size());
    setPixmap(QPixmap::fromImage(QImage(":/images/grid.png")));
    //show();
}

void Map::placeBalls(int level){
    int qntt = 6;
    int number = 1;
    int lessQntBall = 3;
    int lessQntBall2 = 0;
    int maxNumber = 4 + level;
    /* Level 1: balls from 2 to 5
     *         quantity = 6 of each, but just 5 of ball number 3
     * Level 2: balls from 2 to 6
     *          quantity = 4 of each,3 of ball 5; 5 of ball 6
     * Level 3: balls from 2 to 7
     *          quantity = 3 of each
     * Level 4: balls from 2 to 8
     *          quantity = 2 of each,1 of ball 5; 1 of ball 6
     * Level 5: balls from 2 to 9
     *          quantity = 2 of each,1 of ball 7
     * */
    switch (level) {
    case 1:
        qntt = 6;
        lessQntBall = 3;
        lessQntBall2 = 0;
        break;
    case 2:
        qntt = 4;
        lessQntBall = 5;
        lessQntBall2 = 6;
        break;
    case 3:
        qntt = 3;
        lessQntBall = 0;
        lessQntBall2 = 0;
        break;
    case 4:
        qntt = 2;
        lessQntBall = 5;
        lessQntBall2 = 6;
        break;
    case 5:
        qntt = 2;
        lessQntBall = 7;
        lessQntBall2 = 0;
        break;
    }
    int qnttBackup = qntt;
    for(int i = 0; i<9; i++){
        for(int j =0; j<9;j++){
            qntt = qnttBackup;
            number++;
              if(number == lessQntBall){
                  qntt--;
              }else if(number > maxNumber){
                  number = 2;
              }else if(level == 2 && number == lessQntBall2){
                  qntt = 5;
              }
              else if(level == 4 && (number == lessQntBall || number == lessQntBall2)){
                                qntt++;
              }
            for(int n = 0; n < number*qntt;n++){
                if(j>8){
                    j = 0;
                    i = i+1;
                }
                if(i == 9){
                    i = 8;
                    break;
                }
                Ball *b = new Ball(number,QPoint(4+i*43,4+j*41),parentWidget(),QPair<int,int>(j,i));
                balls[j][i] = b;
                b->setImage();
                j++;
            }
            j--;
         }
    }
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    for(int i = 0; i<9; i++){
        for(int j =0; j<9;j++){
            int r = qrand()%9;
            int c = qrand()%9;
            Ball *temp = balls[r][c];
            bMove(i,j,r,c);
            temp->pos = balls[i][j]->pos;
            temp->index = balls[i][j]->index;
            balls[i][j] = temp;
        }
    }
}
void Map::bMove(int fromR,int fromC,int toR,int toC){
    Ball* clicked = balls[fromR][fromC];
    Ball* replace = balls[toR][toC];
    QPoint posFrom = clicked->pos;
    QPoint posTo = replace->pos;
    replace->move(posFrom);
    replace->pos = posFrom;
    replace->index = QPair<int,int>(fromR,fromC);
    clicked->move(posTo);
    clicked->pos = posTo;
    clicked->index = QPair<int,int>(toR,toC);
    balls[toR][toC] = clicked;
    balls[fromR][fromC] = replace;
    clicked->setImage();
    replace->setImage();
}
