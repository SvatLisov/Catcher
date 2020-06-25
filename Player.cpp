#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Enemy.h"
#include <QTimer>
#include <QList>
#include "Game.h"
//внешний глобальный класс
extern Game * game;

Player::Player(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    // создание изображения игрока
    setPixmap(QPixmap(":/new/prefix1/images/14.png"));

    // создание и подключение таймера для для обработки игрока
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}
//создание события-нажатие клавиши
void Player::keyPressEvent(QKeyEvent *event){
    // передвижение в право или в лево игрока
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }

}

void Player::spawn(){
    // создание врага
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

void Player::move(){
    // получить список всех предметов, в настоящее время сталкивающихся с игроком
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // если один из сталкивающихся предметов - враг, уничтожьте
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            // увеличение счетчика
            game->score->increase();

            // удалить врагов с экрана и списка
            scene()->removeItem(colliding_items[i]);

            delete colliding_items[i];

            return;
        }
    }
}
