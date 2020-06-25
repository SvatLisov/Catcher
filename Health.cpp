#include "Health.h"
#include <QFont>
#include "Enemy.h"

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // инцилизация здоровья
    health = 3;

    //прорисовка строки с текущим состоянием здоровья
    setPlainText(QString("Health: ") + QString::number(health)); // Здоровье: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // Здоровье: 2
}

int Health::getHealth(){
      return health;

}
