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

    if (ID == 4) {
        mutex_2.lock();
    }
    else if (ID == 5) {
        mutex_4.lock();
    }
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem 1
            if (y == 30 && x < 330) {
                if (x == 310) {
                    qDebug("T1 LOCK mutex_0");
                    mutex_0.lock();
                }
                x+=10;
            }
            else if (x == 330 && y < 150) {
                if (y == 130) {
                    qDebug("T1 LOCK mutex_2");
                    mutex_2.lock();
                }
                y+=10;
            }
            else if (x > 60 && y == 150) {
                if (x == 310) {
                    qDebug("T1 UNLOCK mutex_0");
                    mutex_0.unlock();
                }
                if (x == 175) {
                    qDebug("T1 UNLOCK mutex_2");
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
                    qDebug("T2 UNLOCK mutex_0");
                    mutex_0.unlock();
                }
                if (x == 580) {
                    qDebug("T2 LOCK mutex_1");
                    mutex_1.lock();
                }
                x+=10;
            }
            else if (x == 600 && y < 150) {
                if (y == 130) {
                    qDebug("T2 LOCK mutex_4");
                    mutex_4.lock();
                }
                y+=10;
            }
            else if (x > 330 && y == 150) {
                if (x == 580) {
                    qDebug("T2 UNLOCK mutex_1");
                    mutex_1.unlock();
                }
                if (x == 485) {
                    qDebug("T2 LOCK mutex_3");
                    mutex_3.lock();
                }
                if (x == 445) {
                    qDebug("T2 UNLOCK mutex_4");
                    mutex_4.unlock();
                }
                if (x == 350) {
                    qDebug("T2 LOCK mutex_0");
                    mutex_0.lock();
                }
                x-=10;
            }
            else {
                if (y == 130) {
                    qDebug("T2 UNLOCK mutex_3");
                    mutex_3.unlock();
                }
                y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 3:     //Trem 3
            if (y == 30 && x < 870) {
                if (x == 620) {
                    qDebug("T3 UNLOCK mutex_1");
                    mutex_1.unlock();
                }
                x+=10;
            }
            else if (x == 870 && y < 150) {
                y+=10;
            }
            else if (x > 600 && y == 150) {
                if (x == 755) {
                    qDebug("T3 LOCK mutex_5");
                    mutex_5.lock();
                }
                if (x == 620) {
                    qDebug("T3 LOCK mutex_1");
                    mutex_1.lock();
                }
                x-=10;
            }
            else {
                if (y == 130) {
                    qDebug("T3 UNLOCK mutex_5");
                    mutex_5.unlock();
                }
                y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 4:     //Trem 4
            if (y == 150 && x < 465) {
                if (x == 310) {
                    qDebug("T4 LOCK mutex_3");
                    mutex_3.lock();
                }
                if (x == 350) {
                    qDebug("T4 UNLOCK mutex_2");
                    mutex_2.unlock();
                }
                if (x == 445) {
                    qDebug("T4 LOCK mutex_6");
                    mutex_6.lock();
                }
                x+=10;
            }
            else if (x == 465 && y < 270) {
                if (y == 170) {
                    qDebug("T4 UNLOCK mutex_3");
                    mutex_3.unlock();
                }
                y+=10;
            }
            else if (x > 195 && y == 270) {
                if (x == 445) {
                    qDebug("T4 UNLOCK mutex_6");
                    mutex_6.unlock();
                }
                x-=10;
            }
            else {
                if (y == 170) {
                    qDebug("T4 LOCK mutex_2");
                    mutex_2.lock();
                }
                y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 5:     //Trem 5
            if (y == 150 && x < 735) {
                if (x == 485) {
                    qDebug("T5 UNLOCK mutex_6");
                    mutex_6.unlock();
                }
                if (x == 580) {
                    qDebug("T5 LOCK mutex_5");
                    mutex_5.lock();
                }
                if (x == 620) {
                    qDebug("T5 UNLOCK mutex_4");
                    mutex_4.unlock();
                }
                x+=10;
            }
            else if (x == 735 && y < 270) {
                if (y == 170) {
                    qDebug("T5 UNLOCK mutex_5");
                    mutex_5.unlock();
                }
                y+=10;
            }
            else if (x > 465 && y == 270) {
                if (x == 485) {
                    qDebug("T5 LOCK mutex_6");
                    mutex_6.lock();
                }
                x-=10;
            }
            else {
                if (y == 170) {
                    qDebug("T5 LOCK mutex_4");
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
