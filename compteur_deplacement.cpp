#include "compteur_deplacement.h"


compteur_deplacement::compteur_deplacement() : d_nombreDeplacements(0) {}

void compteur_deplacement::compterDeplacement(const robot& r) {
    // On suppose que chaque appel à cette méthode signifie que le robot se déplace
    d_nombreDeplacements++;


    std::cout << "Déplacement " << d_nombreDeplacements << " : Position ("
              << nouvellePosition.getX() << ", " << nouvellePosition.getY()
              << "), Direction : " << nouvelleDirection << std::endl;
}


int compteur_deplacement::getNombreDeplacements() const {
    return d_nombreDeplacements;
}

void compteur_deplacement::afficherCompteur() const {
    std::cout << "Nombre total de déplacements : " << d_nombreDeplacements << std::endl;
}
