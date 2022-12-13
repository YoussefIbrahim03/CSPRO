#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

#include "score.h"
#include "health.h"
#include "player.h"

class Game : public QGraphicsView {
public:
    Game(){};
    QGraphicsScene* scene;
    Score* score;
    Player* frank;
};

#endif // GAME_H
