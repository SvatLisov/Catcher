#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QBrush>
#include <QImage>

Game::Game(QWidget *parent){
    // создание поля игры
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    //  фон игры
    setBackgroundBrush(QBrush(QImage(":/new/prefix1/images/12.jpg")));

    // создание размера поля игры
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // создание игрока
    player = new Player();
    // игрок в начале игры находится в середине нижней части экрана
    player->setPos(400,500);
    // сфокусироваться на игроке и установить его в качестве текущего приоритета
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // добавление игрока на экран
    scene->addItem(player);

    // создание посчета жизней и пойманных объектов
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    // создание объектов
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    show();
}
