#include "compteur_rotation.h"
#include "robot.h"

compteur_rotation::compteur_rotation() : nombreRotations(0) {}

int compteur_rotation::getNombreRotations() const {
    return nombreRotations;
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
