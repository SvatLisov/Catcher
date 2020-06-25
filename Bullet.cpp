/*#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"

extern Game * game; //there is an external global object called game

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // draw graphics
    setPixmap(QPixmap(":/new/prefix1/images/14.png"));


    // make/connect a timer to move() the bullet every so often сделать / подключить таймер для перемещения () пули очень часто
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Bullet::move(){
    // get a list of all the items currently colliding with this bullet получить список всех предметов, в настоящее время сталкивающихся с этой пулей
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy  если один из сталкивающихся предметов - враг, уничтожьте и пулю, и врага
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            // increase the score  увеличение
            game->score->increase();

            // remove them from the scene (still on the heap)удалить их со сцены (все еще в куче)
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // delete them from the heap to save memory удалить их из кучи, чтобы сохранить память
            delete colliding_items[i];
            delete this;

            // return (all code below refers to a non existint bullet)возврат (весь приведенный ниже код относится к не существующей пуле)
            return;
        }
    }

    // if there was no collision with an Enemy, move the bullet forward  если не было столкновения с врагом, переместите пулю вперед
    setPos(x(),y()-10);
    // if the bullet is off the screen, destroy it  если пуля находится за пределами экрана, уничтожьте ее
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
*/
