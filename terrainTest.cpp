#define DOCTEST_CONFIG_NO_MULTITHREADING
#include "doctest.h"
#include "terrain.h"
#include <fstream>
#include<iostream>

// Fonction auxiliaire pour créer un fichier temporaire
void creerFichierTest(const std::string& nomFichier, const std::string& contenu) {
    std::ofstream fichier(nomFichier);
    if (fichier.is_open()) {
        fichier << contenu;
        fichier.close();
    }
}

TEST_CASE("Tests pour la classe Terrain") {
    terrain terrain;

    SUBCASE("Chargement depuis un fichier valide") {
        // Contenu du fichier de test
        std::string contenu =
            ".....\n"
            "..D..\n"
            "..A..\n"
            ".....\n";
        std::string nomFichier = "test_terrain.txt";
        creerFichierTest(nomFichier, contenu);

        CHECK(terrain.chargerDepuisFichier(nomFichier) == true);
        CHECK(terrain.getLongueur() == 4); // Nombre de lignes
        CHECK(terrain.getLargeur() == 5);  // Longueur d'une ligne
        remove(nomFichier.c_str());
    }

    SUBCASE("Positions de départ et d'arrivée") {
        std::string contenu =
            ".....\n"
            "..D..\n"
            "..A..\n"
            ".....\n";
        std::string nomFichier = "test_positions.txt";
        creerFichierTest(nomFichier, contenu);

        terrain.chargerDepuisFichier(nomFichier);

        position depart = terrain.getCaseDepart();
        position arrivee = terrain.getCaseArrivee();

        CHECK(depart.getX() == 2);
        CHECK(depart.getY() == 1);

        CHECK(arrivee.getX() == 2);
        CHECK(arrivee.getY() == 2);
        remove(nomFichier.c_str());
    }

    SUBCASE("Terrain vide ou fichier inexistant") {
        // Test avec un fichier vide
        std::string nomFichierVide = "test_vide.txt";
        creerFichierTest(nomFichierVide, "");

        CHECK(terrain.chargerDepuisFichier(nomFichierVide) == true);
        CHECK(terrain.getLongueur() == 0);
        CHECK(terrain.getLargeur() == 0);

        // Test avec un fichier inexistant
        CHECK(terrain.chargerDepuisFichier("inexistant.txt") == false);
        remove(nomFichierVide.c_str());
    }

    SUBCASE("Vérification des cases libres") {
        std::string contenu =
            ".....\n"
            "..D..\n"
            "..A..\n"
            "#####\n";
        std::string nomFichier = "test_cases_libres.txt";
        creerFichierTest(nomFichier, contenu);

        terrain.chargerDepuisFichier(nomFichier);

        // Case libre
        CHECK(terrain.estLibre(position(0, 0)) == true);

        // Case occupée par un mur
        CHECK(terrain.estLibre(position(0, 3)) == false);

        // Case départ et arrivée
        CHECK(terrain.estLibre(position(2, 1)) == true); // 'D'
        CHECK(terrain.estLibre(position(2, 2)) == true); // 'A'

        // Case en dehors des limites
        CHECK(terrain.estLibre(position(-1, 0)) == false);
        CHECK(terrain.estLibre(position(0, -1)) == false);
        CHECK(terrain.estLibre(position(5, 0)) == false);
        CHECK(terrain.estLibre(position(0, 4)) == false);
        remove(nomFichier.c_str());
    }
}
