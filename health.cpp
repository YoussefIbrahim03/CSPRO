#include <QFont>

#include "health.h"

Health::Health(QGraphicsItem* parent) : QGraphicsTextItem(parent) {
    // initializing health to three
    health = 3;

    // draw the text
    setPlainText("Health: " + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void Health::decreaseHealth() {
    health--;
    setPlainText("Health: " + QString::number(health));
}

int Health::getHealth() {
    return health;
}
