#include "compteur_rotation.h"
#include "robot.h"

compteur_rotation::compteur_rotation() : nombreRotations(0) {}

void compteur_rotation::afficherStatistique()
{
    std::cout << "Nombre de rotations : " << nombreRotations << std::endl;
}

void compteur_rotation::reset() {
    nombreRotations = 0;
}

void compteur_rotation::update(const robot& r) {

    static char ancienneDirection = r.getDirection();

    if (r.getDirection() != ancienneDirection) {
        nombreRotations++;
        ancienneDirection = r.getDirection();
    }
}
