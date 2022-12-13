#include "heart.h"

heart::heart(int location)
{
    // Set Image
    QPixmap image("/Users/youssefibrahim/desktop/GTA/heart.jpeg");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(30);
    setPixmap(image);

    // Set Position
    int row,column;
    if(location==1)
    {
    row = 0;
    column = 7;
    }
    if(location==2)
    {
    row = 0;
    column = 8;
    }
    if(location==3)
    {
    row = 0;
    column = 9;
    }
    setPos(50 + column * 50, 50 + row * 50);
}
