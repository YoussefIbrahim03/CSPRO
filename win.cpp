#include "win.h"

win::win()
{
    // Set Image
    QPixmap image("/Users/youssefibrahim/desktop/GTA/youwin.jpeg");
    image = image.scaledToWidth(200);
    image = image.scaledToHeight(200);
    setPixmap(image);

    // Set Position
    int row,column;
    row=5;
    column=5;
    setPos(50 + column * 50, 50 + row * 50);
}
