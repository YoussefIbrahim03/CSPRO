#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <cstdlib>
#include <ctime>
#include "health.h"
#include "player.h"
#include "game.h"

using namespace std;

class enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int row,column;
    int data[11][10];
    Game* game;
    Player* fran;
    enemy* gangster;
    int life=2;
    static int count;
public:
    enemy(int boardData[11][10], Game* game,int enem,Player*frank);
public slots:
    void movement();
    void damagetofrank(int boardData[11][10]);
    static int getenemies();

};

#endif // ENEMY_H
