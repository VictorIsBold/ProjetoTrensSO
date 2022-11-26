#include "trem.h"
#include <QtCore>
#include <QMutex>
#include <QSemaphore>

QMutex mutex_0;
QMutex mutex_1;
QMutex mutex_2;
QMutex mutex_3;
QMutex mutex_4;
QMutex mutex_5;
QMutex mutex_6;

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem 1
            if (y == 30 && x < 330) {
                if (x == 310) {
                    mutex_0.lock();
                }
                x+=10;
            }
            else if (x == 330 && y < 150) {
                if (y == 130) {
                    mutex_2.lock();
                }
                y+=10;
            }
            else if (x > 60 && y == 150) {
                if (x == 310) {
                    mutex_0.unlock();
                }
                else if (x == 175) {
                    mutex_2.unlock();
                }
                x-=10;
            }
            else {
                y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 2:     //Trem 2
            if (y == 30 && x < 600) {
                if (x == 350) {
                    mutex_0.unlock();
                }
                else if (x == 580) {
                    mutex_1.lock();
                }
                x+=10;
            }
            else if (x == 600 && y < 150) {
                if (y == 130) {
                    mutex_4.lock();
                }
                y+=10;
            }
            else if (x > 330 && y == 150) {
                if (x == 580) {
                    mutex_1.unlock();
                }
                else if (x == 485) {
                    mutex_3.lock();
                }
                else if (x == 445) {
                    mutex_4.unlock();
                }
                else if (x == 350) {
                    mutex_0.lock();
                }
                x-=10;
            }
            else {
                if (y == 130) {
                    mutex_3.unlock();
                }
                y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 3:     //Trem 3
            if (y == 30 && x < 870) {
                if (x == 620) {
                    mutex_1.unlock();
                }
                x+=10;
            }
            else if (x == 870 && y < 150) {
                y+=10;
            }
            else if (x > 600 && y == 150) {
                if (x == 755) {
                    mutex_5.lock();
                }
                else if (x == 620) {
                    mutex_1.lock();
                }
                x-=10;
            }
            else {
                if (y == 130) {
                    mutex_5.unlock();
                }
                y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 4:     //Trem 4
            if (y == 150 && x < 465) {
                if (x == 310) {
                    mutex_3.lock();
                }
                else if (x == 350) {
                    mutex_2.unlock();
                }
                else if (x == 445) {
                    mutex_6.lock();
                }
                x+=10;
            }
            else if (x == 465 && y < 270) {
                if (y == 170) {
                    mutex_3.unlock();
                }
                y+=10;
            }
            else if (x > 195 && y == 270) {
                if (x == 445) {
                    mutex_6.unlock();
                }
                x-=10;
            }
            else {
                if (y == 170) {
                    mutex_2.lock();
                }
                y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 5:     //Trem 5
            if (y == 150 && x < 735) {
                if (x == 485) {
                    mutex_6.unlock();
                }
                else if (x == 580) {
                    mutex_5.lock();
                }
                else if (x == 620) {
                    mutex_4.unlock();
                }
                x+=10;
            }
            else if (x == 735 && y < 270) {
                if (y == 170) {
                    mutex_5.unlock();
                }
                y+=10;
            }
            else if (x > 465 && y == 270) {
                if (x == 485) {
                    mutex_6.lock();
                }
                x-=10;
            }
            else {
                if (y == 170) {
                    mutex_4.lock();
                }
                y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;

        default:
            break;
        }
        msleep(velocidade);
    }
}

void Trem::changeSpeed(int speed) {
    velocidade = speed;
}
