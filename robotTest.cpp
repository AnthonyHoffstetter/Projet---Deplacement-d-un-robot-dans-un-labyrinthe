#define DOCTEST_CONFIG_NO_MULTITHREADING
#include "doctest.h"
#include "robot.h"

void lesCoordonnesDuRobotSontExactement(const robot& r, int x, int y, char direction)
{
    REQUIRE(r.getPositionActuelle().getX() == x);
    REQUIRE(r.getPositionActuelle().getY() == y);
    REQUIRE(r.getDirection() == direction);
}

TEST_CASE("[robot] Le robot est bien construit")
{
    int x{1},y{2};
    position p{1,2};
    char direction{'N'};
    robot r{p,direction};
    lesCoordonnesDuRobotSontExactement(r,x,y,direction);
}

TEST_CASE("[robot] les changements de direction fonctionnent")
{
    int x{1},y{1};
    position p{x,y};
    SUBCASE("Tourner a gauche")
    {
        SUBCASE("Depuis la direction Nord")
        {
            robot r{p,'^'};
            r.tournerGauche();
            lesCoordonnesDuRobotSontExactement(r,x,y,'<');
        }
        SUBCASE("Depuis la direction Ouest")
        {
            robot r{p,'<'};
            r.tournerGauche();
            lesCoordonnesDuRobotSontExactement(r,x,y,'v');
        }
        SUBCASE("Depuis la direction Sud")
        {
            robot r{p,'v'};
            r.tournerGauche();
            lesCoordonnesDuRobotSontExactement(r,x,y,'>');
        }
        SUBCASE("Depuis la direction Est")
        {
            robot r{p,'>'};
            r.tournerGauche();
            lesCoordonnesDuRobotSontExactement(r,x,y,'^');
        }
    }
    SUBCASE("Tourner a droite")
    {
        SUBCASE("Depuis la direction Nord")
        {
            robot r{p,'^'};
            r.tournerDroite();
            lesCoordonnesDuRobotSontExactement(r,x,y,'>');
        }
        SUBCASE("Depuis la direction Est")
        {
            robot r{p,'>'};
            r.tournerDroite();
            lesCoordonnesDuRobotSontExactement(r,x,y,'v');
        }
        SUBCASE("Depuis la direction Sud")
        {
            robot r{p,'v'};
            r.tournerDroite();
            lesCoordonnesDuRobotSontExactement(r,x,y,'<');
        }
        SUBCASE("Depuis la direction Ouest")
        {
            robot r{p,'<'};
            r.tournerDroite();
            lesCoordonnesDuRobotSontExactement(r,x,y,'^');
        }
    }
}

TEST_CASE("[robot] Le robot avance")
{
    int x{1},y{1};
    position p{x,y};
    SUBCASE("Vers le Nord")
    {
        robot r{p,'^'};
        r.avancer();
        lesCoordonnesDuRobotSontExactement(r,1,0,'^');
    }
    SUBCASE("Vers l'Est")
    {
        robot r{p,'>'};
        r.avancer();
        lesCoordonnesDuRobotSontExactement(r,2,1,'>');
    }
    SUBCASE("Vers le Sud")
    {
        robot r{p,'v'};
        r.avancer();
        lesCoordonnesDuRobotSontExactement(r,1,2,'v');
    }
    SUBCASE("Vers l'Ouest")
    {
        robot r{p,'<'};
        r.avancer();
        lesCoordonnesDuRobotSontExactement(r,0,1,'<');
    }
}
