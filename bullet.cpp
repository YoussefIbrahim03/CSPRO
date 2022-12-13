#include "bullet.h"

bullet::bullet(int location)
{
    // Set Image
    QPixmap image("/Users/youssefibrahim/desktop/GTA/bullet.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);

    // Set Position
    int row,column;
    if(location==1)
    {
    row = 2;
    column = 1;
    }
    if(location==2)
    {
    row = 9;
    column = 1;
    }
    if(location==3)
    {
    row = 2;
    column = 8;
    }
    if(location==4)
    {
    row = 9;
    column = 8;
    }
    setPos(50 + column * 50, 50 + row * 50);
}
