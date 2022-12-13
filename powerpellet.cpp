#include "powerpellet.h"

powerpellet::powerpellet(int num)
{
    // Set Image
    QPixmap image("/Users/youssefibrahim/desktop/GTA/goldskull.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);

    // Set Position
    int row,column;
    if(num==1)
    {
    row = 6;
    column = 5;
    }
    if(num==2)
    {
    row = 8;
    column = 6;
    }
    setPos(50 + column * 50, 50 + row * 50);
}
