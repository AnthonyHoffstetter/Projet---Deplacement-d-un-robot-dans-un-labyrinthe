#include "algorithmepledge.h"
#include <iostream>

using namespace std;

void algorithmePledge::executer(robot &r, const terrain &t)
{
    int compteurOrientation = 0;

    while (r.getPositionActuelle() != t.getCaseArrivee())
    {
        if (compteurOrientation == 0)
        {
            if (!r.detecterObstacleDevant(t))
            {
                r.avancer();
            }
            else
            {
                r.tournerGauche();
                compteurOrientation++;
            }
        }
        else
        {
            if (!r.detecterObstacleDroite(t))
            {
                r.tournerDroite();
                compteurOrientation--;
                r.avancer();
            }
            else if (!r.detecterObstacleDevant(t))
            {
                r.avancer();
            }
            else
            {
                r.tournerGauche();
                compteurOrientation++;
            }
        }
    }


}
