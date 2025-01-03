
#include "programme.h"
#include <iostream>

using namespace std;

// Constructeur
programme::programme() : terrainCharge(false) {

}

// Méthode d'initialisation
void programme::initialiser() {
    if (ter.chargerDepuisFichier("./test.txt")) {
        cout<<"Terrain charge avec succes"<<endl;
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
        cerr << "Erreur : Le terrain n'a pas ete charge. Initialisez d'abord le programme." << endl;
        return;
    }

    cout<<"Quel type d'affichage voulez vous ? : 1 pour texte simple, 2 pour texte ameliore 1, 3 pour texte ameliore 2"<<endl;
    int choixAffichage;
    cin>>choixAffichage;
    while(!choisirAffichage(choixAffichage,ter))
    {
        cout<<"Veuillez saisir un numero valide (1 : texte simple, 2 : texte ameliore 1, 3 : texte ameliore 2)"<<endl;
        cin>>choixAffichage;
        choisirAffichage(choixAffichage,ter);
    }


    compteur_deplacement* compteur = new compteur_deplacement();
    afficheur = std::make_unique<afficheurRobot>();
    calcul_temps* timer = new calcul_temps(); // Observateur pour mesurer le temps
    compteur_rotation* compteurRot = new compteur_rotation(); // Observateur pour le nombre de rotations


    // Récupérer les positions de départ et d'arrivée
    position depart = ter.getCaseDepart();
    position arrivee = ter.getCaseArrivee();

    // Configurer le robot et enregistrer les observateurs
    robot r(depart, 'v');
    //r.enregistrerObservateur(std::move(compteur));
    r.enregistrerObservateur(std::unique_ptr<compteur_deplacement>(compteur));
    r.enregistrerObservateur(std::move(afficheur));
    r.enregistrerObservateur(std::unique_ptr<calcul_temps>(timer)); // Enregistrement du calcul_temps
    r.enregistrerObservateur(std::unique_ptr<compteur_rotation>(compteurRot)); // Enregistrement du compteur de rotations


    // Choix de l'algorithme
    int choix;
    cout<< endl;
    cout<< endl;
    cout << "Choisissez un algorithme: 1 pour Algorithme Main Droite, 2 pour Algorithme Pledge" << endl;
    cout<< endl;
    cin >> choix;
    cout<< endl;


    choisirAlgorithme(choix, r, ter);

    // Afficher les résultats
    cout<< endl;
    cout<< endl;
    cout<< endl;
    cout<< endl;
    cout<< endl;
    cout<< endl;
    cout<< endl;
    cout<< endl;
    cout<< endl;
    cout<< endl;
    cout<< endl;
    cout << "Position de depart : (" << depart.getX() << ", " << depart.getY() << ")" << endl;
    cout << "Position d'arrivee : (" << arrivee.getX() << ", " << arrivee.getY() << ")" << endl;
    compteur->afficherStatistique();
    compteurRot->afficherStatistique();
    timer->afficherStatistique();
    cout<< endl;
    cout<< endl;
    }

// Méthode pour choisir et exécuter un algorithme
void programme::choisirAlgorithme(int choix, robot& r, terrain& ter) {
    if (choix == 1) {
        algorithmeMainDroite algo;
        algo.executer(r, ter);
    } else if (choix == 2) {
        algorithmePledge algo;
        algo.executer(r, ter);
    } else {
        cerr << "Choix invalide. Aucun algorithme execute." << endl;
    }
}

bool programme::choisirAffichage(int choix,terrain& ter) {
    system("cls");
    if (choix == 1) {
        ter.afficher();
        return true;
    } else if (choix == 2) {
        ter.transformerTexteAmeliore1();
        ter.afficher();
        return true;
    }
    else if (choix == 3) {
        ter.transformerTexteAmeliore1();
        ter.afficherTexteAmeliore2();
        return true;
    }
    else {
        return false;
    }
}


