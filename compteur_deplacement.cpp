#include "compteur_deplacement.h"

compteur_deplacement::compteur_deplacement() : d_nombreDeplacements(0) {}

void compteur_deplacement::compterDeplacement() {
    // On suppose que chaque appel à cette méthode signifie que le robot se déplace
    d_nombreDeplacements++;
}

int compteur_deplacement::getNombreDeplacements() const {
    return d_nombreDeplacements;
}
