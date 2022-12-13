#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <cstdlib>
#include <ctime>
#include "enemy.h"
#include "health.h"
#include "player.h"
#include "game.h"

using namespace std;
    int enemy::count=0;

    enemy::enemy(int boardData[11][10], Game* game,int enem,Player*frank)
    {
        // Set Image
        QPixmap image("/Users/youssefibrahim/desktop/GTA/gangsta.png");
        image = image.scaledToWidth(50);
        image = image.scaledToHeight(50);
        setPixmap(image);


        if(enem==1)
        {
        row = 8;
        column = 1;
        }
        if(enem==2)
        {
        row = 8;
        column = 8;
        }
        setPos(50 + column * 50, 50 + row * 50);

        // Set data Array
        for (int i = 0; i < 11; i++)
            for (int j = 0; j < 10; j++)
                data[i][j] = boardData[i][j];
        this->game=game;
        fran=frank;
        /*gangster=this->enemy;*/
        ++count;
    }
    void enemy::movement()
    {
        int x = rand()%4+1;
    srand((unsigned) time(NULL));
    if (x==1 && data[row - 1][column] >= 0)
    {
        row--;
    }
    else if (x==2 && data[row + 1][column] >= 0)
    {
        row++;
    }
    else if (x==3 && data[row][column + 1] >= 0)
    {
        column++;
    }
    else if (x==4 && data[row][column - 1] >= 0)
    {
        column--;
    }
    setPos(50 + column * 50, 50 + row * 50);

    damagetofrank(data);

    }
    void enemy::damagetofrank(int boardData[11][10])
    {
        QList<QGraphicsItem*> items = collidingItems();
        for (int i = 0; i < items.size(); i++)
        {
            if (typeid(*items[i]) == typeid(Player)&& (fran->getpower()))
            {
                fran->respawn(boardData,fran);
            }
        }
    }

    int enemy::getenemies()
    {
        return count;
    }



