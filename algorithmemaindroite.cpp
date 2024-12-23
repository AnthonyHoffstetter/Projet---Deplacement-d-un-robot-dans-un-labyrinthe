#include "algorithmemaindroite.h"

void algorithmeMainDroite::executer(robot& r,const terrain& ter)
{
    // Tant que le robot n'est pas à la sortie
    while (r.getPositionActuelle() != ter.getCaseArrivee())
    {
        // Si le robot peut tourner à droite
        if (!r.detecterObstacleDroite(ter))
        {
            r.tournerDroite();
            r.avancer();
        }
        // Sinon, s'il peut avancer tout droit
        else if (!r.detecterObstacleDevant(ter))
        {
            r.avancer();
        }
        // Sinon, tourner à gauche
        else
        {
            r.tournerGauche();
        }
    }
}
