#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QTimer>
#include "player.h"
#include "score.h"
#include "game.h"
#include "enemy.h"
#include "powerpellet.h"
#include "bullet.h"
#include "heart.h"
#include "house.h"
#include "enemydeath.h"
#include "win.h"
#include "lose.h"
//#include "DirectedUnweightedGraph.h"
#include <QDebug>

using namespace std;



int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    QGraphicsView view;
    QGraphicsScene scene;
    Game * game= new Game();



    // qDebug() << "here"; // You can use this for tracing

    view.setFixedSize(600, 600);
    view.setWindowTitle("Maze Game");
    QBrush brush(Qt::black);
    view.setBackgroundBrush(brush);

    QFile file("/Users/youssefibrahim/desktop/GTA/Board.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    int boardData[11][10];
    QString temp;
    for (int i = 0; i < 11; i++)
        for (int j = 0; j < 10; j++)
        {
            stream >> temp;
            boardData[i][j] = temp.toInt();
        }

    QPixmap grassImage("/Users/youssefibrahim/desktop/GTA/road.png");
    grassImage = grassImage.scaledToWidth(50);
    grassImage = grassImage.scaledToHeight(50);

    QPixmap bricksImage("/Users/youssefibrahim/desktop/GTA/wall.png");
    bricksImage = bricksImage.scaledToWidth(50);
    bricksImage = bricksImage.scaledToHeight(50);

    QGraphicsPixmapItem boardItems[11][10];
    //int counter=0;
    for (int i = 0; i < 11; i++)
        for (int j = 0; j < 10; j++)
        {
            // Set Image
            if (boardData[i][j] < 0)
                boardItems[i][j].setPixmap(bricksImage);
            else if(boardData[i][j] != 100)
            {
                boardItems[i][j].setPixmap(grassImage);
                //counter++;
            }
            // Set Position
            boardItems[i][j].setPos(50 + j * 50, 50 + i * 50);

            // Add to the Scene
            scene.addItem(&boardItems[i][j]);
        }




    Player franklin(boardData);
    scene.addItem(&franklin);
    game->frank=&franklin;

    house home;
    scene.addItem(&home);

    enemy enemy1(boardData, game, 1, game->frank);
    scene.addItem(&enemy1);
    enemy enemy2(boardData, game, 2, game->frank);
    scene.addItem(&enemy2);
    QTimer *timer=new QTimer();
    timer->start(1000);
    Game::connect(timer, &QTimer::timeout, &enemy1, &enemy::movement);
    Game::connect(timer, &QTimer::timeout, &enemy2, &enemy::movement);


    bullet bullet1(1);
    scene.addItem(&bullet1);
    bullet bullet2(2);
    scene.addItem(&bullet2);
    bullet bullet3(3);
    scene.addItem(&bullet3);
    bullet bullet4(4);
    scene.addItem(&bullet4);

    heart heart1(1);
    scene.addItem(&heart1);
    heart heart2(2);
    scene.addItem(&heart2);
    heart heart3(3);
    scene.addItem(&heart3);

    powerpellet powerpellet1(1);
    scene.addItem(&powerpellet1);
    powerpellet powerpellet2(2);
    scene.addItem(&powerpellet2);

    win winpic;
    lose losepic;

    enemydeath checker(&franklin, &enemy1, &enemy2, &scene, &heart1, &heart2, &heart3, &home, &winpic, &losepic);

    franklin.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    franklin.setFocus();


    view.setScene(&scene);
    view.show();


    QTimer *mytimer=new QTimer();
    mytimer->start(1);
    Game::connect(mytimer,&QTimer::timeout,&checker, &enemydeath::check);

    return a.exec();


}

