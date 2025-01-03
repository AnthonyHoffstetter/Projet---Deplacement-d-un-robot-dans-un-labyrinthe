#ifndef COMPTEUR_ROTATION_H
#define COMPTEUR_ROTATION_H

#include "observateur.h"
#include "robot.h"

// Déclaration de la classe compteur_rotation
class compteur_rotation : public observateur {
private:
    int nombreRotations;  // Nombre de rotations effectuées

public:
    // Constructeur par défaut
    compteur_rotation();


    // Méthode pour réinitialiser le compteur
    void reset();

    // Méthode appelée lorsque l'état du robot change (rotation détectée)
    void update(const robot& r) override;
    virtual void afficherStatistique() override;
};

#endif // COMPTEUR_ROTATION_H
