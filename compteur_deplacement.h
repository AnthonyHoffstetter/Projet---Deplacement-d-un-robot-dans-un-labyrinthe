
#ifndef COMPTEUR_DEPLACEMENT_H
#define COMPTEUR_DEPLACEMENT_H

#include "robot.h"  // Pour manipuler le robot

class compteur_deplacement {
public:
    compteur_deplacement();
    void compterDeplacement();
    int getNombreDeplacements() const;

private:
    int d_nombreDeplacements;
};

#endif // COMPTEUR_DEPLACEMENT_H
