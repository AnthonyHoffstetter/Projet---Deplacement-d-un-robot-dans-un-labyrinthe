#include "compteur_deplacement.h"


compteur_deplacement::compteur_deplacement() : d_nombreDeplacements(0) {}


void compteur_deplacement::update(const robot &r)
{
    d_nombreDeplacements++;
}

int compteur_deplacement::getNombreDeplacements() const
{
    return d_nombreDeplacements;
}


void compteur_deplacement::afficherStatistique()
{
    std::cout << "Nombre de deplacements : " << d_nombreDeplacements << std::endl;
}


