#define DOCTEST_CONFIG_NO_MULTITHREADING
#include "doctest.h"
#include "algorithmemaindroite.h"
#include "algorithmepledge.h"
#include <fstream>

TEST_CASE("[algorithme] L'algorithme main droite atteint l'arrivée")
{
    SUBCASE("En commencant directement a cote d'un mur")
    {
        terrain t;
        string terrainData =
            "X.....A\n"
            "X....XX\n"
            "XD....X\n"
            "XXXXXXX";

        const string fichierTerrain = "terrain.txt";
        ofstream fichier(fichierTerrain);
        fichier << terrainData;
        fichier.close();

        REQUIRE(t.chargerDepuisFichier(fichierTerrain));

        position p=t.getCaseDepart();
        robot r{p, 'v'};

        algorithmeMainDroite algo;
        algo.executer(r, t);

        REQUIRE(r.getPositionActuelle()==t.getCaseArrivee());
        remove(fichierTerrain.c_str());
    }
    SUBCASE("En commencant pas a cote d'un mur")
    {
        terrain t;
        string terrainData =
            "X.....A\n"
            "X.D..XX\n"
            "X.....X\n"
            "XXXXXXX";

        const string fichierTerrain = "terrain.txt";
        ofstream fichier(fichierTerrain);
        fichier << terrainData;
        fichier.close();

        REQUIRE(t.chargerDepuisFichier(fichierTerrain));

        position p=t.getCaseDepart();
        robot r{p, 'v'};

        algorithmeMainDroite algo;
        algo.executer(r, t);

        REQUIRE(r.getPositionActuelle()==t.getCaseArrivee());
        remove(fichierTerrain.c_str());
    }


}

TEST_CASE("[algorithme] L'algorithme Pledge atteint l'arrivée")
{
    terrain t;
        string terrainData =
            "X.....A\n"
            "X.D..XX\n"
            "X.....X\n"
            "XXXXXXX";

        const string fichierTerrain = "terrain.txt";
        ofstream fichier(fichierTerrain);
        fichier << terrainData;
        fichier.close();

        REQUIRE(t.chargerDepuisFichier(fichierTerrain));

        position p=t.getCaseDepart();
        robot r{p, 'v'};

        algorithmePledge algo;
        algo.executer(r, t);

        REQUIRE(r.getPositionActuelle()==t.getCaseArrivee());
        remove(fichierTerrain.c_str());
}
