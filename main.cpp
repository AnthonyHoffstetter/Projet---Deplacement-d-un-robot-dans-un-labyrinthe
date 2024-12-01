#include <iostream>
#include "position.h"
#include "Terrain.h"

using namespace std;

//Transformer cette fonction en test unitaire ! #Anthony
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


void testterrain() {

// Création d'un objet Terrain
    Terrain ter{};

    // Chargement du terrain depuis le fichier "test.txt"
    if (ter.chargerDepuisFichier("./test.txt")) {
        // Affichage du terrain après le chargement
        std::cout << "Terrain chargé avec succès :" << std::endl;
        ter.afficher();

        // Affichage des coordonnées de départ et d'arrivée

    position depart = ter.getCaseDepart();
     position arrivee = ter.getCaseArrivee();

        std::cout << "Position de départ : (" << depart.getX() << ", " << depart.getY() << ")" << std::endl;
        std::cout << "Position d'arrivée : (" << arrivee.getX() << ", " << arrivee.getY() << ")" << std::endl;
    } else {
        // Gestion des erreurs si le fichier n'est pas trouvé ou invalide
        std::cerr << "Erreur : Impossible de charger le terrain depuis le fichier test.txt" << std::endl;
    }



}

int main()
{
}
