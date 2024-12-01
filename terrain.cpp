#include "terrain.h"
#include <fstream>
#include <iostream>

using namespace std;

bool Terrain::chargerDepuisFichier(const string& nomFichier) {
    ifstream fichier(nomFichier); 
    if (!fichier.is_open()) {
        cerr << "Erreur : Impossible d'ouvrir le fichier " << nomFichier << endl;
        return false;
    }

    d_terrain.clear(); 
    string ligne;
    int y = 0;

    while (getline(fichier, ligne)) {
        vector<char> ligneTerrain;
        for (int x = 0; x < (int)ligne.size(); ++x) {
            char c = ligne[x];
            ligneTerrain.push_back(c);

            if (c == 'D') { 
                d_depart.setPosition(x, y);
            } else if (c == 'A') { 
                d_arrivee.setPosition(x, y);
            }
        }
        d_terrain.push_back(ligneTerrain);
        ++y;
    }

    d_longueur = d_terrain.size();                
    d_largeur = d_terrain.empty() ? 0 : d_terrain[0].size(); 
    fichier.close();
    return true;
}
