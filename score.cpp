#include "score.h"

#include <QFont>

Score::Score(QGraphicsItem* parent) : QGraphicsTextItem(parent) {
    // initializing score to zero
    score = 0;

    // draw the text
    setPlainText("Score: " + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}

void Score::increaseScore() {
    score++;
    setPlainText("Score: " + QString::number(score));
}

int Score::getScore() {
    return score;
}
