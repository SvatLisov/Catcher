#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // инициализация счетчика
    score = 0;

    // прорисовка строки с текущим состоянием счетчика
    setPlainText(QString("Score: ") + QString::number(score)); // Счет: 0
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}

void Score::increase(){
    score++;
    setPlainText(QString("Score: ") + QString::number(score)); // Счет: 1
}

int Score::getScore(){
    return score;
}
