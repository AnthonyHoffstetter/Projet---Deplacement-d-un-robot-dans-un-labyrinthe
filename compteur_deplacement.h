#ifndef COMPTEUR_DEPLACEMENT_H
#define COMPTEUR_DEPLACEMENT_H

#include "observateur.h"
#include <iostream>


class compteur_deplacement : public observateur {
private:
    int d_nombreDeplacements;

public:

    compteur_deplacement();


    void update(const position& nouvellePosition, char nouvelleDirection) override;


    int getNombreDeplacements() const;


    void afficherCompteur() const;
};

#endif // COMPTEUR_DEPLACEMENT_H
