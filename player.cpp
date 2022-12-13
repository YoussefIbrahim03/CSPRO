#include "player.h"
#include "QtCore/qtimer.h"
#include "bullet.h"
#include "powerpellet.h"
#include "enemy.h"
#include "house.h"
#include "pointers.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>

Player::Player(int boardData[11][10])
{
    {
        // Set Image
        QPixmap image("/Users/youssefibrahim/desktop/GTA/Tweety.png");
        image = image.scaledToWidth(50);
        image = image.scaledToHeight(50);
        setPixmap(image);

        // Set Position
        row = 5;
        column = 4;
        QGraphicsPixmapItem::setPos(50 + column * 50, 50 + row * 50);

        // Set data Array
        for (int i = 0; i < 11; i++)
            for (int j = 0; j < 10; j++)
                data[i][j] = boardData[i][j];


    }
}

void Player::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Up && data[row - 1][column] >= 0)
    {
        row--;
        QList<QGraphicsItem*> items = QGraphicsPixmapItem::collidingItems();
        for (int i = 0; i < items.size(); i++)
        {
            if (typeid(*items[i]) == typeid(house))
            {
                QGraphicsPixmapItem::scene()->removeItem(items[i]);
            }
        }
    }
    else if (event->key() == Qt::Key_Down && data[row + 1][column] >= 0)
    {
        row++;
        QList<QGraphicsItem*> items = QGraphicsPixmapItem::collidingItems();
        for (int i = 0; i < items.size(); i++)
        {
            if (typeid(*items[i]) == typeid(house))
            {
                QGraphicsPixmapItem::scene()->removeItem(items[i]);
            }
        }

    }
    else if (event->key() == Qt::Key_Right && data[row][column + 1] >= 0)
    {
        column++;
        QList<QGraphicsItem*> items = QGraphicsPixmapItem::collidingItems();
        for (int i = 0; i < items.size(); i++)
        {
            if (typeid(*items[i]) == typeid(house))
            {
                QGraphicsPixmapItem::scene()->removeItem(items[i]);
            }
        }

    }
    else if (event->key() == Qt::Key_Left && data[row][column - 1] >= 0)
    {
        column--;
        QList<QGraphicsItem*> items = QGraphicsPixmapItem::collidingItems();
        for (int i = 0; i < items.size(); i++)
        {
            if (typeid(*items[i]) == typeid(house))
            {
                QGraphicsPixmapItem::scene()->removeItem(items[i]);
            }
        }

    }
    QGraphicsPixmapItem::setPos(50 + column * 50, 50 + row * 50);

    QList<QGraphicsItem*> items = QGraphicsPixmapItem::collidingItems();
    for (int i = 0; i < items.size(); i++)
    {
        if (typeid(*items[i]) == typeid(bullet))
        {
            QGraphicsPixmapItem::scene()->removeItem(items[i]);
            bullets_x=bullets_x+1;
        }
        if (typeid(*items[i]) == typeid(powerpellet))
        {
            QGraphicsPixmapItem::scene()->removeItem(items[i]);
            notpower=false;
        }
        if (typeid(*items[i]) == typeid(enemy)&& notpower)
        {
            // Set Image
            QPixmap image("/Users/youssefibrahim/desktop/GTA/Tweety.png");
            image = image.scaledToWidth(50);
            image = image.scaledToHeight(50);
            setPixmap(image);

            // Set Position
            row = 5;
            column = 4;
            QGraphicsPixmapItem::setPos(50 + column * 50, 50 + row * 50);

            // Set data Array
            for (int i = 0; i < 11; i++)
                for (int j = 0; j < 10; j++)
                    data[i][j] = data[i][j];

            life--;
        }
    }
}

void Player::respawn(int boardData[11][10],Player* frank)
{
    {
        if(life>0)
        {
        // Set Image
        QPixmap image("/Users/youssefibrahim/desktop/GTA/Tweety.png");
        image = image.scaledToWidth(50);
        image = image.scaledToHeight(50);
        setPixmap(image);

        // Set Position
        row = 5;
        column = 4;
        QGraphicsPixmapItem::setPos(50 + column * 50, 50 + row * 50);

        // Set data Array
        for (int i = 0; i < 11; i++)
            for (int j = 0; j < 10; j++)
                data[i][j] = boardData[i][j];

        life--;

        }

    }
}


int Player::getbulletsx()
{
    return bullets_x;
}

int Player::gethealth()
{
    return life;
}

void Player::power()
{
    notpower=true;
}

bool Player::getpower()
{
    return notpower;
}


