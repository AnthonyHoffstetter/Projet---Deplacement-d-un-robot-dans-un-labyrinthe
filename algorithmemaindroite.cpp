#include "algorithmemaindroite.h"

void algorithmeMainDroite::executer(robot& r,const terrain& ter)
{
    if(!r.detecterObstacleDroite(ter))
    {
        while (!r.detecterObstacleDevant(ter) && r.getPositionActuelle() != ter.getCaseArrivee())
        {
            r.avancer();
        }
        r.tournerGauche();
    }

    while (r.getPositionActuelle() != ter.getCaseArrivee())
    {
        if (!r.detecterObstacleDroite(ter))
        {
            r.tournerDroite();
            r.avancer();
        }
        else if (!r.detecterObstacleDevant(ter))
        {
            r.avancer();
        }
        else
        {
            r.tournerGauche();
        }
    }
}
