#include "afficheurrobot.h"

void afficheurRobot::update(const robot &r)
{
    goto_xy(r.getAnciennePosition().getX(),r.getAnciennePosition().getY());
    std::cout<<".";
    goto_xy(r.getPositionActuelle().getX(),r.getPositionActuelle().getY());
    std::cout<<r.getDirection();
    Sleep(500);
}
