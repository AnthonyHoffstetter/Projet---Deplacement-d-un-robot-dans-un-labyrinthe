#include <iostream>
#include "position.h"
#include "Terrain.h"
#include "robot.h"
#include "algorithmemaindroite.h"
#include "compteur_deplacement.h"
#include "afficheurrobot.h"


using namespace std;

/**Transformer cette fonction en test unitaire */
void testPosition()
{
    position p1(2,5);
    position p2(3,7);
    position p3(2,5);
    cout<<"p1.x = "<<p1.getX()<<" et p1.y = "<<p1.getY()<<endl;
    if(p1==p2)
        cout<<"p1 et p2 sont egaux"<<endl;
    if(p1==p3)
        cout<<"p1 et p3 sont egaux"<<endl;
    if(p1!=p2)
        cout<<"p1 et p2 sont differents"<<endl;
}

/**Transformer cette fonction en test unitaire */
void testterrain() {

// Création d'un objet Terrain
    terrain ter{};
    compteur_deplacement* compteur = new compteur_deplacement();
    afficheurRobot* afficheur = new afficheurRobot();


    // Chargement du terrain depuis le fichier "test.txt"
    if (ter.chargerDepuisFichier("./test.txt")) {
        // Affichage du terrain après le chargement
        //std::cout << "Terrain chargé avec succès :" << std::endl;
        ter.afficher();

        // Affichage des coordonnées de départ et d'arrivée

    position depart = ter.getCaseDepart();
     position arrivee = ter.getCaseArrivee();

     //ajouter par Antho pour tester l'algorithmeMainDroite
     robot r(depart,'v');
     r.enregistrerObservateur(std::unique_ptr<compteur_deplacement>(compteur));
     r.enregistrerObservateur(std::unique_ptr<afficheurRobot>(afficheur));
     algorithmeMainDroite a;
     a.executer(r,ter);

        std::cout << "Position de départ : (" << depart.getX() << ", " << depart.getY() << ")" << std::endl;
        std::cout << "Position d'arrivée : (" << arrivee.getX() << ", " << arrivee.getY() << ")" << std::endl;
        std::cout << "Nombre de deplacement" << compteur->getNombreDeplacements();
    } else {
        // Gestion des erreurs si le fichier n'est pas trouvé ou invalide
        std::cerr << "Erreur : Impossible de charger le terrain depuis le fichier test.txt" << std::endl;
    }



}


int main()
{
    testterrain();
}
