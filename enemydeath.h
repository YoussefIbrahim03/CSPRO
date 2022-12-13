#ifndef ENEMYDEATH_H
#define ENEMYDEATH_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include "player.h"
#include "enemy.h"
#include "heart.h"
#include "house.h"
#include "win.h"
#include "lose.h"

class enemydeath : public QObject, public QGraphicsPixmapItem
{
private:
    Player * gggg;
    enemy * e1;
    enemy *e2;
    QGraphicsScene *xscene;
    heart *heart11;
    heart *heart12;
    heart *heart13;
    house *homie;
    win *winner;
    lose *loser;

public:
    enemydeath(Player *ggg, enemy *e12, enemy *e21, QGraphicsScene *xscene1, heart *h1,heart *h2, heart* h3,house *homex,win *winer, lose *losser);
public slots:
    void check();
    
};

#endif // ENEMYDEATH_H
