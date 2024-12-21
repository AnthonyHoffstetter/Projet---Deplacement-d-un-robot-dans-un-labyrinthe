#define DOCTEST_CONFIG_NO_MULTITHREADING
#include "doctest.h"
#include "robot.h"
#include "fakeobservateur.h"

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
            robot r{p,'N'};
            r.tournerGauche();
            lesCoordonnesDuRobotSontExactement(r,x,y,'O');
        }
        SUBCASE("Depuis la direction Ouest")
        {
            robot r{p,'O'};
            r.tournerGauche();
            lesCoordonnesDuRobotSontExactement(r,x,y,'S');
        }
        SUBCASE("Depuis la direction Sud")
        {
            robot r{p,'S'};
            r.tournerGauche();
            lesCoordonnesDuRobotSontExactement(r,x,y,'E');
        }
        SUBCASE("Depuis la direction Est")
        {
            robot r{p,'E'};
            r.tournerGauche();
            lesCoordonnesDuRobotSontExactement(r,x,y,'N');
        }
    }
    SUBCASE("Tourner a droite")
    {
        SUBCASE("Depuis la direction Nord")
        {
            robot r{p,'N'};
            r.tournerDroite();
            lesCoordonnesDuRobotSontExactement(r,x,y,'E');
        }
        SUBCASE("Depuis la direction Est")
        {
            robot r{p,'E'};
            r.tournerDroite();
            lesCoordonnesDuRobotSontExactement(r,x,y,'S');
        }
        SUBCASE("Depuis la direction Sud")
        {
            robot r{p,'S'};
            r.tournerDroite();
            lesCoordonnesDuRobotSontExactement(r,x,y,'O');
        }
        SUBCASE("Depuis la direction Ouest")
        {
            robot r{p,'O'};
            r.tournerDroite();
            lesCoordonnesDuRobotSontExactement(r,x,y,'N');
        }
    }
}

TEST_CASE("[robot] Le robot avance")
{
    int x{1},y{1};
    position p{x,y};
    SUBCASE("Vers le Nord")
    {
        robot r{p,'N'};
        r.avancer();
        lesCoordonnesDuRobotSontExactement(r,1,0,'N');
    }
    SUBCASE("Vers l'Est")
    {
        robot r{p,'E'};
        r.avancer();
        lesCoordonnesDuRobotSontExactement(r,2,1,'E');
    }
    SUBCASE("Vers le Sud")
    {
        robot r{p,'S'};
        r.avancer();
        lesCoordonnesDuRobotSontExactement(r,1,2,'S');
    }
    SUBCASE("Vers l'Ouest")
    {
        robot r{p,'O'};
        r.avancer();
        lesCoordonnesDuRobotSontExactement(r,0,1,'O');
    }
}

TEST_CASE("[robot] Enregistrement d'un observateur")
{
    int x{1}, y{1};
    position p{x, y};
    SUBCASE("Enregistrer un observateur dans le robot")
    {
        robot r{p, 'N'};
        auto obs = std::make_unique<fakeObservateur>();
        r.enregistrerObservateur(std::move(obs));
        REQUIRE(r.nombreObservateurs() == 1);
    }
    SUBCASE("Enregistrer plusieurs observateurs")
    {
        robot r{p, 'N'};
        auto obs1 = std::make_unique<fakeObservateur>();
        auto obs2 = std::make_unique<fakeObservateur>();

        r.enregistrerObservateur(std::move(obs1));
        r.enregistrerObservateur(std::move(obs2));

        REQUIRE(r.nombreObservateurs() == 2);
    }
    SUBCASE("Ne pas enregistrer d'observateur") {

        robot r{p, 'N'};
        REQUIRE(r.nombreObservateurs() == 0);
    }
}
