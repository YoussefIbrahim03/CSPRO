#include "house.h"

house::house()
{
    // Set Image
    QPixmap image("/Users/youssefibrahim/desktop/GTA/house.gif");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);

    // Set Position
    int row,column;
    row = 5;
    column = 4;
    
    setPos(50 + column * 50, 50 + row * 50);
}
