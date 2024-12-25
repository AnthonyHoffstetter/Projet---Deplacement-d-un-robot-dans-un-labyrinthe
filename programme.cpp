// programme.cpp
#include "programme.h"
#include <iostream>

using namespace std;

// Constructeur
programme::programme() : terrainCharge(false) {
    compteur = std::make_unique<compteur_deplacement>();
    afficheur = std::make_unique<afficheurRobot>();
}

// Méthode d'initialisation
void programme::initialiser() {
    if (ter.chargerDepuisFichier("./test.txt")) {
        cout << "Terrain chargé avec succès :" << endl;
        ter.afficher();
        terrainCharge = true;
    } else {
        cerr << "Erreur : Impossible de charger le terrain depuis le fichier test.txt" << endl;
        terrainCharge = false;
    }
}

// Méthode pour exécuter le choix d'algorithme
void programme::executerChoixAlgorithme() {
    initialiser();
    if (!terrainCharge) {
        cerr << "Erreur : Le terrain n'a pas été chargé. Initialisez d'abord le programme." << endl;
        return;
    }

    // Récupérer les positions de départ et d'arrivée
    position depart = ter.getCaseDepart();
    position arrivee = ter.getCaseArrivee();

    // Configurer le robot et enregistrer les observateurs
    robot r(depart, 'v');
    r.enregistrerObservateur(std::move(compteur));
    r.enregistrerObservateur(std::move(afficheur));

    // Choix de l'algorithme
    int choix;
    cout << "Choisissez un algorithme: 1 pour Algorithme Main Droite, 2 pour Algorithme Pledge" << endl;
    cin >> choix;
    choisirAlgorithme(choix, r, ter);

    // Afficher les résultats
    cout << "Position de départ : (" << depart.getX() << ", " << depart.getY() << ")" << endl;
    cout << "Position d'arrivée : (" << arrivee.getX() << ", " << arrivee.getY() << ")" << endl;

    // Re-créer le compteur pour récupérer le nombre de déplacements
    // En supposant que vous avez un mécanisme pour obtenir le compteur actuel
    cout << "Nombre de déplacements : " << compteur->getNombreDeplacements() << endl;
    }

// Méthode pour choisir et exécuter un algorithme
void programme::choisirAlgorithme(int choix, robot& r, terrain& ter) {
    if (choix == 1) {
        cout << "Exécution de l'Algorithme Main Droite" << endl;
        algorithmeMainDroite algo;
        algo.executer(r, ter);
    } else if (choix == 2) {
        cout << "Exécution de l'Algorithme Pledge" << endl;
        algorithmePledge algo;
        algo.executer(r, ter);
    } else {
        cerr << "Choix invalide. Aucun algorithme exécuté." << endl;
    }
}
