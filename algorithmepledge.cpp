#include "algorithmepledge.h"
#include <iostream>

using namespace std;

void algorithmePledge::executer(robot &r, const terrain &t)
{
    int compteurOrientation = 0; // Compteur pour suivre les rotations du robot

    // Tant que le robot n'est pas � la sortie
    while (r.getPositionActuelle() != t.getCaseArrivee())
    {
        if (compteurOrientation == 0)
        {
            // Si le compteur est � z�ro, on avance directement
            if (!r.detecterObstacleDevant(t))
            {
                r.avancer();
            }
            else
            {
                // Sinon, on commence � contourner les obstacles
                r.tournerGauche();
                compteurOrientation++; // Ajouter +1 pour la rotation � gauche
            }
        }
        else
        {
            // Suivre la m�thode de la main droite
            if (!r.detecterObstacleDroite(t))
            {
                r.tournerDroite();
                compteurOrientation--; // Soustraire -1 pour la rotation � droite
                r.avancer();
            }
            else if (!r.detecterObstacleDevant(t))
            {
                r.avancer();
            }
            else
            {
                r.tournerGauche();
                compteurOrientation++; // Ajouter +1 pour la rotation � gauche
            }
        }
    }

    // Message de fin
    cout << "Le robot a atteint la sortie avec succ�s !" << endl;
}
