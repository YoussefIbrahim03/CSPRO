#include "enemydeath.h"
#include "QtCore/qtimer.h"

enemydeath::enemydeath(Player *ggg, enemy *e12, enemy *e21, QGraphicsScene *xscene1, heart *h1, heart *h2, heart *h3,house *homex,win* winer, lose* losser)
{
    gggg=ggg;
    e1=e12;
    e2=e21;
    xscene=xscene1;
    heart11=h1;
    heart12=h2;
    heart13=h3;
    homie=homex;
    winner=winer;
    loser=losser;
}

void enemydeath::check()
{
    if (gggg->getbulletsx()==2)
    {

        xscene->removeItem(e1);
    }

    if (gggg->getbulletsx()==4)
    {

        xscene->removeItem(e2);
        xscene->addItem(homie);
        xscene->addItem(winner);

    }
    if(gggg->getpower()==false)
    {
        QTimer *ytimer=new QTimer();
        ytimer->start(10000);
        connect(ytimer,&QTimer::timeout,gggg, &Player::power);
    }
    if(gggg->gethealth()==2)
    {
        xscene->removeItem(heart11);
    }
    if(gggg->gethealth()==1)
    {
        xscene->removeItem(heart12);
    }
    if(gggg->gethealth()==0)
    {
        xscene->removeItem(heart13);
        xscene->removeItem(gggg);
        xscene->addItem(loser);
    }

}
