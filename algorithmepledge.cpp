#include "algorithmepledge.h"
#include <iostream>

using namespace std;

void algorithmePledge::executer(robot &r, const terrain &t)
{
    int compteurOrientation = 0; // Compteur pour suivre les rotations du robot

    // Tant que le robot n'est pas à la sortie
    while (r.getPositionActuelle() != t.getCaseArrivee())
    {
        if (compteurOrientation == 0)
        {
            // Si le compteur est à zéro, on avance directement
            if (!r.detecterObstacleDevant(t))
            {
                r.avancer();
            }
            else
            {
                // Sinon, on commence à contourner les obstacles
                r.tournerGauche();
                compteurOrientation++; // Ajouter +1 pour la rotation à gauche
            }
        }
        else
        {
            // Suivre la méthode de la main droite
            if (!r.detecterObstacleDroite(t))
            {
                r.tournerDroite();
                compteurOrientation--; // Soustraire -1 pour la rotation à droite
                r.avancer();
            }
            else if (!r.detecterObstacleDevant(t))
            {
                r.avancer();
            }
            else
            {
                r.tournerGauche();
                compteurOrientation++; // Ajouter +1 pour la rotation à gauche
            }
        }

        // Afficher la position et l'état du compteur
        cout << "Position actuelle : (" << r.getPositionActuelle().getX() << ", "
             << r.getPositionActuelle().getY() << ") | Compteur d'orientation : "
             << compteurOrientation << endl;
    }

    // Message de fin
    cout << "Le robot a atteint la sortie avec succès !" << endl;
}
