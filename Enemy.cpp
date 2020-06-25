#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "Game.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    // создание рандомной позиции объектов
    int random_number = rand() % 700;
    setPos(random_number,0);

    // прорисовка объектов
    setPixmap(QPixmap(":/new/prefix1/images/123.png"));
    setTransformOriginPoint(50,50);
    setRotation(180);

    // создание и подключение таймера для перемещения объектов
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // включение таймера
    timer->start(50);
}

void Enemy::move(){
    // движение объектов вниз
    setPos(x(),y()+5);

    // уничтожение объекта, когда он доходит то конца экрана
    if (pos().y() > 600){

      //отнимание жизней
       game->health->decrease();
       scene()->removeItem(this);
       delete this;
        }
  }
