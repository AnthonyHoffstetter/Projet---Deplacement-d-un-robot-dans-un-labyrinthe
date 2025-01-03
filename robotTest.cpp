#define DOCTEST_CONFIG_NO_MULTITHREADING
#include "doctest.h"
#include "robot.h"
#include <fstream>

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


TEST_CASE("[robot] Notification des observateurs")
{
    position p{1, 1};
    char direction{'N'};
    robot r{p, direction};


    class fake_observateur : public observateur {
    public:
        bool notifie = false;

        void update(const robot& r) override
        {
            notifie = true;
        }
        void afficherStatistique() override{}
    };

    auto obs1 = std::make_unique<fake_observateur>();
    auto obs2 = std::make_unique<fake_observateur>();

    fake_observateur& ref_obs1 = *obs1;
    fake_observateur& ref_obs2 = *obs2;

    r.enregistrerObservateur(std::move(obs1));
    r.enregistrerObservateur(std::move(obs2));

    r.notifierObservateurs();

    REQUIRE(ref_obs1.notifie == true);
    REQUIRE(ref_obs2.notifie == true);
}

TEST_CASE("[robot] Détection d'obstacle devant")
{
    terrain t;
    string terrainData =
        "......\n"
        "....X.\n"
        "D..X.X\n"
        "A...X.";

    const string fichierTerrain = "terrain.txt";
    ofstream fichier(fichierTerrain);
    fichier << terrainData;
    fichier.close();

    REQUIRE(t.chargerDepuisFichier(fichierTerrain));

    SUBCASE("Le robot regarde vers le Nord et il n'y a pas d'obstacle")
    {
        position p{2, 1};
        robot r{p, '^'};
        REQUIRE(r.detecterObstacleDevant(t) == false);
    }

    SUBCASE("Le robot regarde vers le Sud et il n'y a pas d'obstacle")
    {
        position p{2, 1};
        robot r{p, 'v'};
        REQUIRE(r.detecterObstacleDevant(t) == false);
    }

    SUBCASE("Le robot regarde vers l'Est et il n'y a pas d'obstacle")
    {
        position p{2, 1};
        robot r{p, '>'};
        REQUIRE(r.detecterObstacleDevant(t) == false);
    }

    SUBCASE("Le robot regarde vers l'Ouest et il n'y a pas d'obstacle")
    {
        position p{2, 1};
        robot r{p, '<'};
        REQUIRE(r.detecterObstacleDevant(t) == false);
    }

    SUBCASE("Le robot regarde vers le Nord et il y a un obstacle")
    {
        position p{4, 2};
        robot r{p, '^'};
        REQUIRE(r.detecterObstacleDevant(t) == true);
    }

    SUBCASE("Le robot regarde vers le Sud et il y a un obstacle")
    {
        position p{4, 2};
        robot r{p, 'v'};
        REQUIRE(r.detecterObstacleDevant(t) == true);
    }

    SUBCASE("Le robot regarde vers l'Est et il y a un obstacle")
    {
        position p{4, 2};
        robot r{p, '>'};
        REQUIRE(r.detecterObstacleDevant(t) == true);
    }

    SUBCASE("Le robot regarde vers l'Ouest et il y a un obstacle")
    {
        position p{4, 2};
        robot r{p, '<'};
        REQUIRE(r.detecterObstacleDevant(t) == true);
    }

    remove(fichierTerrain.c_str());
}

TEST_CASE("[robot] Détection d'obstacle a droite")
{
    terrain t;
    string terrainData =
        "......\n"
        "....X.\n"
        "D..X.X\n"
        "A...X.";

    const string fichierTerrain = "terrain.txt";
    ofstream fichier(fichierTerrain);
    fichier << terrainData;
    fichier.close();

    REQUIRE(t.chargerDepuisFichier(fichierTerrain));

    SUBCASE("Le robot regarde vers le Nord et il n'y a pas d'obstacle a droite")
    {
        position p{2, 1};
        robot r{p, '^'};
        REQUIRE(r.detecterObstacleDroite(t) == false);
    }

    SUBCASE("Le robot regarde vers le Sud et il n'y a pas d'obstacle a droite")
    {
        position p{2, 1};
        robot r{p, 'v'};
        REQUIRE(r.detecterObstacleDroite(t) == false);
    }

    SUBCASE("Le robot regarde vers l'Est et il n'y a pas d'obstacle a droite")
    {
        position p{2, 1};
        robot r{p, '>'};
        REQUIRE(r.detecterObstacleDroite(t) == false);
    }

    SUBCASE("Le robot regarde vers l'Ouest et il n'y a pas d'obstacle a droite")
    {
        position p{2, 1};
        robot r{p, '<'};
        REQUIRE(r.detecterObstacleDroite(t) == false);
    }

    SUBCASE("Le robot regarde vers le Nord et il y a un obstacle a droite")
    {
        position p{4, 2};
        robot r{p, '^'};
        REQUIRE(r.detecterObstacleDroite(t) == true);
    }

    SUBCASE("Le robot regarde vers le Sud et il y a un obstacle a droite")
    {
        position p{4, 2};
        robot r{p, 'v'};
        REQUIRE(r.detecterObstacleDroite(t) == true);
    }

    SUBCASE("Le robot regarde vers l'Est et il y a un obstacle a droite")
    {
        position p{4, 2};
        robot r{p, '>'};
        REQUIRE(r.detecterObstacleDroite(t) == true);
    }

    SUBCASE("Le robot regarde vers l'Ouest et il y a un obstacle a droite")
    {
        position p{4, 2};
        robot r{p, '<'};
        REQUIRE(r.detecterObstacleDroite(t) == true);
    }

    remove(fichierTerrain.c_str());
}
