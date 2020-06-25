#include <QApplication>
#include "Game.h"
#include <QFont>
// глобальный класс
Game * game;



int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    game = new Game();
    game->show();


        return a.exec();

        return 0;
    }

