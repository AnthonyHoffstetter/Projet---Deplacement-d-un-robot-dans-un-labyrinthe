#include "terrain.h"
#include <fstream>
#include <iostream>

using namespace std;

terrain::terrain()
{
    d_terrain.clear(); // Initialise la grille comme vide
}

bool terrain::chargerDepuisFichier(const string& nomFichier) {
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
                d_depart.setPosition(x,y);
            } else if (c == 'A') {
                d_arrivee.setPosition(x,y);
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

void terrain::afficher() const {
    for (const auto& ligne : d_terrain) {
        for (char c : ligne) {
            cout << c;
        }
        cout << endl;
    }
}
void terrain::afficherAmeliore() const {
    if (d_terrain.empty()) {
        cout << "Terrain vide." << endl;
        return;
    }

    // Créer la bordure supérieure
    string bordureHaut = "+" + string(d_largeur, '-') + "+";
    cout << bordureHaut << endl;

    // Afficher chaque ligne du terrain
    for (const auto& ligne : d_terrain) {
        for (size_t x = 0; x < ligne.size(); ++x) {
            char c = ligne[x];

            // Convertir les caractères du terrain
            if (c == 'X') {
                // Vérifier si c'est un mur horizontal ou vertical
                if (x > 0 && ligne[x - 1] == 'X') {
                    cout << '-'; // Mur horizontal
                } else {
                    cout << '|'; // Mur vertical
                }
            } else if (c == '.') {
                cout << '.'; // Espace vide
            } else if (c == 'D') {
                cout << 'D'; // Point de départ
            } else if (c == 'A') {
                cout << 'A'; // Point d'arrivée
            } else if (c == '>') {
                cout << '>'; // Objet spécial
            } else {
                cout << c; // Tout autre caractère
            }
        }
        cout << "|" << endl; // Bordure droite
    }

    // Créer la bordure inférieure
    cout << bordureHaut << endl;
}


int terrain::getLargeur() const {
    return d_largeur;
}

int terrain::getLongueur() const {
    return d_longueur;
}

position terrain::getCaseDepart() const {
    return d_depart;
}

position terrain::getCaseArrivee() const {
    return d_arrivee;
}

bool terrain::estLibre(const position& sp) const {
    int x = sp.getX();
    int y = sp.getY();

    if (x < 0 || x >= d_largeur || y < 0 || y >= d_longueur) {
        return false;
    }

    return d_terrain[y][x] == '.' || d_terrain[y][x] == 'A' || d_terrain[y][x] == 'D';
}
