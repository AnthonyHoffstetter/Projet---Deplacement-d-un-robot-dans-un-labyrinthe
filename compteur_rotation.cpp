#include "compteur_rotation.h"
#include "robot.h"

// Constructeur par défaut
compteur_rotation::compteur_rotation() : nombreRotations(0) {}

// Retourner le nombre de rotations effectuées
int compteur_rotation::getNombreRotations() const {
    return nombreRotations;
}

// Réinitialiser le compteur à zéro
void compteur_rotation::reset() {
    nombreRotations = 0;
}

// Mettre à jour le compteur lorsque l'état du robot change
void compteur_rotation::update(const robot& r) {
    // Si le robot a tourné à gauche ou à droite, incrémenter le compteur
    static char ancienneDirection = r.getDirection();

    if (r.getDirection() != ancienneDirection) {
        nombreRotations++;
        ancienneDirection = r.getDirection();  // Met à jour la direction précédente
    }
}
