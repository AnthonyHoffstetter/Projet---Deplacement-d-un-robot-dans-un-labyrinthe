#define DOCTEST_CONFIG_NO_MULTITHREADING
#include "doctest.h"
#include "programme.h"
#include "terrain.h"
#include "robot.h"
#include "algorithmeMainDroite.h"
#include "algorithmePledge.h"
/*
// Test de la méthode d'initialisation
TEST_CASE("Initialisation du programme") {
    programme p;

    SUBCASE("Initialisation avec un fichier valide") {
        p.initialiser();
        REQUIRE_EQ(p.isTerrainCharge(), true); // Le terrain doit être chargé avec succès
    }

    SUBCASE("Initialisation avec un fichier invalide") {
        // Simuler un fichier inexistant ou invalide
        // Note : vous pouvez temporairement modifier `test.txt` pour qu'il soit invalide.
        p.initialiser();
        REQUIRE_EQ(p.isTerrainCharge(), true); // Le terrain ne doit pas être chargé
    }
}

// Test de la méthode de choix d'algorithme
TEST_CASE("Choisir et exécuter un algorithme") {
    programme p;
    p.initialiser();

    SUBCASE("Exécuter Algorithme Main Droite") {
        robot r(p.returnterain().getCaseDepart(), 'v');
        p.choisirAlgorithme(1, r, p.returnterain()); // Choix 1 : Main Droite

        // Vérifier que le robot atteint la position d'arrivée
        REQUIRE_EQ(r.getPositionActuelle(), p.returnterain().getCaseArrivee());
    }

    SUBCASE("Exécuter Algorithme Pledge") {
        robot r(p.returnterain().getCaseDepart(), 'v');
        p.choisirAlgorithme(2, r, p.returnterain()); // Choix 2 : Pledge

        // Vérifier que le robot atteint la position d'arrivée
        REQUIRE_EQ(r.getPositionActuelle(), p.returnterain().getCaseArrivee());
    }

    SUBCASE("Exécuter avec un choix invalide") {
        robot r(p.returnterain().getCaseDepart(), 'v');
        p.choisirAlgorithme(99, r, p.returnterain()); // Choix invalide

        // Dans ce cas, on ne vérifie pas la position car rien ne se passe
        REQUIRE_EQ(r.getPositionActuelle(), p.returnterain().getCaseDepart());
    }
}*/
