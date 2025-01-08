#include "compteur_rotation.h"
#include "robot.h"

compteur_rotation::compteur_rotation(char direction) : nombreRotations(0),ancienneDirection{direction} {}

void compteur_rotation::afficherStatistique()
{
    std::cout << "Nombre de rotations : " << nombreRotations << std::endl;
}

void compteur_rotation::reset() {
    nombreRotations = 0;
}

int compteur_rotation::getNombreRotations() const
{
    return nombreRotations;
}

void compteur_rotation::update(const robot& r) {

    if (r.getDirection() != ancienneDirection) {
        nombreRotations++;
        ancienneDirection = r.getDirection();
    }
}
