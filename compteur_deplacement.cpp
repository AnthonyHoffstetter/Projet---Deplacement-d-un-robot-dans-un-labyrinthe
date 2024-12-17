#include "compteur_deplacement.h"


compteur_deplacement::compteur_deplacement() : d_nombreDeplacements(0) {}


void compteur_deplacement::update(const position& nouvellePosition, char nouvelleDirection) {

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
