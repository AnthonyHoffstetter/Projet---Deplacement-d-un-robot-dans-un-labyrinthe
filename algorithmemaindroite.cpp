#include "algorithmemaindroite.h"

void algorithmeMainDroite::executer(robot& r,const terrain& ter)
{
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
