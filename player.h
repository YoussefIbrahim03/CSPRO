#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QGraphicsRectItem>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int row, column;
    int data[11][10];
    int life=3;
    int bullets_x=0;
    bool notpower=true;
public:
    Player(int boardData[11][10]);
    void keyPressEvent(QKeyEvent* event);
    int bulletss();
    void respawn(int boardData[11][10],Player* frank);
    int getbulletsx();
    int gethealth();
    bool getpower();
public slots:
    void power();

};

#endif // PLAYER_H
