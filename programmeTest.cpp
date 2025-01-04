#define DOCTEST_CONFIG_NO_MULTITHREADING
#include "doctest.h"
#include "programme.h"
#include "terrain.h"
#include "robot.h"
#include "algorithmeMainDroite.h"
#include "algorithmePledge.h"
#include <fstream>

TEST_CASE("[Programme] Le programme est correctement construit")
{
   programme p;
   REQUIRE(p.isTerrainCharge()==false);
}

TEST_CASE("[Programme] Le chargement du fichier fonctionne")
{
    SUBCASE("Quand le fichier est correct")
    {
        programme p;
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
        p.chargerFichier("terrain.txt");
        REQUIRE(p.isTerrainCharge()==true);
        remove(fichierTerrain.c_str());
    }
    SUBCASE("Quand le fichier n'existe pas")
    {
        programme p;
        terrain t;
        p.chargerFichier("terrain.txt");
        REQUIRE(p.isTerrainCharge()==false);
    }
}

TEST_CASE("[robot] Le robot est correctement initialise")
{
    programme p;
    string terrainData =
    "......\n"
    "....X.\n"
    "D..X.X\n"
    "A...X.";

    const string fichierTerrain = "terrain.txt";
    ofstream fichier(fichierTerrain);
    fichier << terrainData;
    fichier.close();
    p.chargerFichier("terrain.txt");
    robot r{};
    p.initialisationRobot(r);
    REQUIRE(r.getPositionActuelle().getX()==0);
    REQUIRE(r.getPositionActuelle().getY()==2);
    REQUIRE(r.nombreObservateurs()==4);
    remove(fichierTerrain.c_str());

}



