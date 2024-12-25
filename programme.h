#ifndef PROGRAMME_H_INCLUDED
#define PROGRAMME_H_INCLUDED


#include "terrain.h"
#include "robot.h"
#include "compteur_deplacement.h"
#include "afficheurRobot.h"
#include "algorithmeMainDroite.h"
#include"algorithmePledge.h"

// Classe principale du programme
class programme {
public:
    // Constructeur
    programme();

    // Méthode d'initialisation
    void initialiser();

    // Méthode pour exécuter le choix d'algorithme
    void executerChoixAlgorithme();

private:
    // Méthode pour choisir et exécuter un algorithme
    void choisirAlgorithme(int choix, robot& r, terrain& ter);

    // Attributs
    bool terrainCharge; // Indique si le terrain a été chargé
    terrain ter;        // Objet terrain
    std::unique_ptr<compteur_deplacement> compteur; // Observateur pour compter les déplacements
    std::unique_ptr<afficheurRobot> afficheur; // Observateur pour afficher les déplacements
};



#endif // PROGRAMME_H_INCLUDED
