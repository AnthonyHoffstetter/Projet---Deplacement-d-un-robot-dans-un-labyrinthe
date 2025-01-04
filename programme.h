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

class programme {
public:

    programme();
    void chargerFichier(const string &nomFichier);
    bool isTerrainCharge() const { return terrainCharge; }
    void initialisationRobot(robot &r);
    void executer();
    void choisirAlgorithme(robot &r);
    void choisirAffichage();


private:

    bool terrainCharge;
    terrain ter;

};



#endif // PROGRAMME_H_INCLUDED
