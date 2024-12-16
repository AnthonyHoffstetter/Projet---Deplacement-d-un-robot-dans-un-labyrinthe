#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "compteur_deplacement.h"


TEST_CASE("Test de la classe compteur_deplacement") {
    // Création d'un objet compteur
    compteur_deplacement compteur;

    SUBCASE("Test de l'initialisation du compteur") {
        // Utilisation de EQ pour vérifier que le nombre de déplacements est 0 au départ
        REQUIRE_EQ(compteur.getNombreDeplacements(), 0);
    }

    SUBCASE("Test après un déplacement") {
        compteur.compterDeplacement();
        // Utilisation de EQ pour vérifier que le nombre de déplacements est 1 après un déplacement
        REQUIRE_EQ(compteur.getNombreDeplacements(), 1);
    }

    SUBCASE("Test après deux déplacements") {
        compteur.compterDeplacement();
        compteur.compterDeplacement();
        // Utilisation de EQ pour vérifier que le nombre de déplacements est 2 après deux déplacements
        REQUIRE_EQ(compteur.getNombreDeplacements(), 2);
    }

    SUBCASE("Test d'un autre objet compteur sans déplacements") {
        compteur_deplacement compteur2;
        // Utilisation de EQ pour vérifier que le compteur d'un nouvel objet commence à 0
        REQUIRE_EQ(compteur2.getNombreDeplacements(), 0);
    }

    SUBCASE("Test de l'absence de déplacement") {
        compteur_deplacement compteur3;
        // Utilisation de EQ pour vérifier qu'aucun déplacement n'a eu lieu, donc le compteur reste à 0
        REQUIRE_EQ(compteur3.getNombreDeplacements(), 0);
    }
}
