#define DOCTEST_CONFIG_NO_MULTITHREADING
#include "doctest.h"
#include "position.h"

void lesCoordonnesDeLaPositionSontExactement(const position& p,int x, int y)
{
    REQUIRE( p.getX() == x );
    REQUIRE( p.getY() == y );
}

TEST_CASE("[position] Les positions sont bien construites")
{
    SUBCASE("Le constructeur avec des coordonnees est correct" )
    {
        int x {2}, y {3};
        position p1 {x,y};
        lesCoordonnesDeLaPositionSontExactement(p1, x, y);
    }
    SUBCASE("Le constructeur par defaut est correct" )
    {
        position p2 {};
        lesCoordonnesDeLaPositionSontExactement(p2, 0, 0);
    }
}


TEST_CASE("[position] Modifier les coordonnees d'une position fonctionne")
{
    int x1{5}, y1{6};
    int x2{8}, y2{9};

    position p(x1, y1);

    // Vérification avant la modification
    lesCoordonnesDeLaPositionSontExactement(p, x1, y1);

    // Modification des coordonnees
    p.setPosition(x2, y2);

    // Vérification après la modification
    lesCoordonnesDeLaPositionSontExactement(p, x2, y2);
}

TEST_CASE("[position] Comparaison de positions")
{
    position p1(1, 2);
    position p2(1, 2);
    position p3(3, 4);

    SUBCASE("Les positions égales doivent être détectées")
    {
        REQUIRE(p1 == p2);  // p1 et p2 doivent être égales
        REQUIRE_FALSE(p1 == p3);  // p1 et p3 ne doivent pas être égales
    }

    SUBCASE("Les positions différentes doivent être détectées")
    {
        REQUIRE(p1 != p3);  // p1 et p3 doivent être différentes
        REQUIRE_FALSE(p1 != p2);  // p1 et p2 ne doivent pas être différentes
    }
}
