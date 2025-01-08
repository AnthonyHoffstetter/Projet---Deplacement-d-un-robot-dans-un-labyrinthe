#define DOCTEST_CONFIG_NO_MULTITHREADING
#include "doctest.h"
#include "compteur_deplacement.h"
#include "compteur_rotation.h"
#include "robot.h"

TEST_CASE("Test de mise à jour du nombre de deplacements")
{
    compteur_deplacement cd;
    robot r;
    SUBCASE("Quand il y a eu aucun deplacement")
    {
        REQUIRE_EQ(cd.getNombreDeplacements(),0);
    }
    SUBCASE("Après un déplacement")
    {
        cd.update(r);
        REQUIRE_EQ(cd.getNombreDeplacements(),1);
    }
    SUBCASE("Après plusieurs deplacements")
    {
        cd.update(r);
        cd.update(r);
        REQUIRE_EQ(cd.getNombreDeplacements(),2);
    }
}

TEST_CASE("Test de mise à jour du nombre de rotations")
{
    compteur_rotation cr('v');
    robot r;
    SUBCASE("Quand il n'y a eu aucun deplacement")
    {
        REQUIRE_EQ(cr.getNombreRotations(),0);
    }
    SUBCASE("Quand il y a un deplacement sans rotation")
    {
        r.avancer();
        cr.update(r);
        REQUIRE_EQ(cr.getNombreRotations(),0);
    }
    SUBCASE("Quand il y a un deplacement avec rotation")
    {
        r.tournerGauche();
        cr.update(r);
        REQUIRE_EQ(cr.getNombreRotations(),1);
    }
    SUBCASE("Quand il y a plusieurs rotations")
    {
        r.tournerGauche();
        cr.update(r);
        r.tournerGauche();
        cr.update(r);
        REQUIRE_EQ(cr.getNombreRotations(),2);
    }
    SUBCASE("Quand il y a plusieurs deplacement avec et sans rotations")
    {
        r.tournerGauche();
        cr.update(r);
        r.tournerGauche();
        cr.update(r);
        r.avancer();
        cr.update(r);
        r.avancer();
        cr.update(r);
        REQUIRE_EQ(cr.getNombreRotations(),2);
    }
}

