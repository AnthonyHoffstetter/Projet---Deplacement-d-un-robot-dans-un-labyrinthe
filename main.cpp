#include <iostream>
#include "position.h"
#include "Terrain.h"
#include "robot.h"
#include "algorithmemaindroite.h"
#include "compteur_deplacement.h"
#include "afficheurrobot.h"
#include "calcul_temps.h"
#include "programme.h"


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
    calcul_temps* timer = new calcul_temps(); // Observateur pour mesurer le temps

    // Chargement du terrain depuis le fichier "test.txt"
    if (ter.chargerDepuisFichier("./test.txt")) {
        // Affichage du terrain
        std::cout << "=== Terrain chargé ===" << std::endl;
        ter.afficher();

        // Ajout d'un espace après l'affichage du labyrinthe
        std::cout << "\n\n";

        // Affichage des coordonnées de départ et d'arrivée
        position depart = ter.getCaseDepart();
        position arrivee = ter.getCaseArrivee();

        // Initialisation du robot
        robot r(depart, 'v');
        r.enregistrerObservateur(std::unique_ptr<compteur_deplacement>(compteur));
        r.enregistrerObservateur(std::unique_ptr<afficheurRobot>(afficheur));
        r.enregistrerObservateur(std::unique_ptr<calcul_temps>(timer)); // Enregistrement du calcul_temps

        // Exécution de l'algorithme de la main droite
        algorithmeMainDroite a;
        a.executer(r, ter);
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;

        // Séparateur pour les statistiques
        std::cout << "=== Statistiques ===" << std::endl;

        // Affichage des statistiques
        std::cout << "Position de départ : (" << depart.getX() << ", " << depart.getY() << ")" << std::endl;
        std::cout << "Position d'arrivée : (" << arrivee.getX() << ", " << arrivee.getY() << ")" << std::endl;
        std::cout << "Nombre de déplacements : " << compteur->getNombreDeplacements() << std::endl;
        timer->afficherTempsTotal(); // Afficher le temps total écoulé
    } else {
        std::cerr << "Erreur : Impossible de charger le terrain depuis le fichier test.txt" << std::endl;
    }
}



int main()
{
    //testterrain();

    programme pro;
    pro.executerChoixAlgorithme();

}
