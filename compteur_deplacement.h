#ifndef COMPTEUR_DEPLACEMENT_H
#define COMPTEUR_DEPLACEMENT_H

#include "observateur.h"
#include <iostream>


class compteur_deplacement : public observateur {
private:
    int d_nombreDeplacements;

public:

    compteur_deplacement();

    void update(const robot &r) override;
    virtual void afficherStatistique() override;

};

#endif // COMPTEUR_DEPLACEMENT_H
