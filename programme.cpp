
#include "programme.h"
#include <iostream>

using namespace std;

programme::programme() : terrainCharge(false) {

}


void programme::chargerFichier(const string &nomFichier)
{
    if (ter.chargerDepuisFichier(nomFichier)) {
        cout<<"Terrain charge avec succes"<<endl;
        terrainCharge = true;
    } else {
        cerr << "Erreur : Impossible de charger le terrain depuis le fichier "<<nomFichier<< endl;
        terrainCharge = false;
    }
}

void programme::executer()
{
    chargerFichier("./test.txt");
    if (!terrainCharge)
    {
        cerr << "Erreur : Le terrain n'a pas ete charge. Initialisez d'abord le programme." << endl;
        return;
    }
    choisirAffichage();
    robot r{};
    initialisationRobot(r);
    choisirAlgorithme(r);

    cout<< endl;
    cout<< endl;
    cout<< endl;
    cout<< endl;
    cout<< endl;
    cout<< endl;
    cout<< endl;
    cout<< endl;
    cout << "Position de depart : (" << ter.getCaseDepart().getX() << ", " << ter.getCaseArrivee().getY() << ")" << endl;
    cout << "Position d'arrivee : (" << r.getPositionActuelle().getX() << ", " << r.getPositionActuelle().getY() << ")" << endl;
    r.afficherStatistiquesObservateurs();
}

void programme::initialisationRobot(robot &r)
{
    r.setPosition(ter.getCaseDepart());

    afficheurRobot* afficheur = new afficheurRobot();
    compteur_deplacement* compteur = new compteur_deplacement();
    compteur_rotation* compteurRot = new compteur_rotation(r.getDirection());
    calcul_temps* timer = new calcul_temps();

    r.enregistrerObservateur(std::unique_ptr<compteur_deplacement>(compteur));
    r.enregistrerObservateur(std::unique_ptr<afficheurRobot>(afficheur));
    r.enregistrerObservateur(std::unique_ptr<calcul_temps>(timer));
    r.enregistrerObservateur(std::unique_ptr<compteur_rotation>(compteurRot));
}


void programme::choisirAlgorithme(robot &r)
{
    int choix;
    cout<< endl;
    cout<< endl;
    cout<< "Choisissez un algorithme: 1 pour Algorithme Main Droite, 2 pour Algorithme Pledge" << endl;
    cout<< endl;
    cin >> choix;
    cout<< endl;
    while(choix!=1 && choix!=2)
    {
        cout<<"Veuillez saisir un numéro valide (1 : Algorithme main droite, 2 : Algorithme Pledge)"<<endl;
        cin>>choix;
    }
    if (choix == 1) {
        algorithmeMainDroite algo;
        algo.executer(r, ter);
    } else if (choix == 2) {
        algorithmePledge algo;
        algo.executer(r, ter);
    }
}

void programme::choisirAffichage()
{
    cout<<"Quel type d'affichage voulez vous ? : 1 pour texte simple, 2 pour texte ameliore 1, 3 pour texte ameliore 2"<<endl;
    int choix;
    cin>>choix;
    while(choix!=1 && choix!=2 && choix!=3)
    {
        system("cls");
        cout<<"Veuillez saisir un numero valide (1 : texte simple, 2 : texte ameliore 1, 3 : texte ameliore 2)"<<endl;
        cin>>choix;
    }
    system("cls");
    if (choix == 1) {
        ter.afficher();
    } else if (choix == 2) {
        ter.transformerTexteAmeliore1();
        ter.afficher();
    }
    else if (choix == 3) {
        ter.transformerTexteAmeliore1();
        ter.afficherTexteAmeliore2();
    }
}


