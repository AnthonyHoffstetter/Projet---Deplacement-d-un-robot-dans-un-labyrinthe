#ifndef PROGRAMME_H_INCLUDED
#define PROGRAMME_H_INCLUDED


#include "terrain.h"
#include "robot.h"
#include "compteur_deplacement.h"
#include "afficheurRobot.h"
#include "algorithmeMainDroite.h"
#include"algorithmePledge.h"
#include "calcul_temps.h"
#include "compteur_rotation.h"

using namespace std ;
// Classe principale du programme
class programme {
public:
    // Constructeur
    programme();

    // Méthode d'initialisation
    void initialiser();
      bool isTerrainCharge() const { return terrainCharge; }
      terrain& returnterain() {return ter; }

    // Méthode pour exécuter le choix d'algorithme
    void executerChoixAlgorithme();
    void choisirAlgorithme(int choix, robot& r, terrain& ter);
    void choisirAffichage(int choix,terrain &ter);

private:
    // Méthode pour choisir et exécuter un algorithme

    // Attributs
    bool terrainCharge; // Indique si le terrain a été chargé
    terrain ter;        // Objet terrain
    unique_ptr<compteur_deplacement> compteur;

    unique_ptr<afficheurRobot> afficheur; // Observateur pour afficher les déplacements
};



#endif // PROGRAMME_H_INCLUDED
