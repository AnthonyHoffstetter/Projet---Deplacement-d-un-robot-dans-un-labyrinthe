#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>
#include <string>
#include <iostream>
#include "position.h"

class Terrain {
public:

    Terrain();

    bool chargerDepuisFichier(const std::string& nomFichier);

    void afficher() const;

    int getLargeur() const;
    int getLongueur() const;

    position getCaseDepart() const;
    position getCaseArrivee() const;

    bool estLibre(const position& sp) const;

private:
    std::vector<std::vector<char>> d_terrain;
    int d_largeur;
    int d_longueur;
    position d_depart;
    position d_arrivee;
};

#endif

