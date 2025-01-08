#define DOCTEST_CONFIG_NO_MULTITHREADING
#include "doctest.h"
#include "programme.h"
#include "terrain.h"
#include "robot.h"
#include "algorithmeMainDroite.h"
#include "algorithmePledge.h"
#include <fstream>

TEST_CASE("[programme] Le programme est correctement construit")
{
   programme p;
   REQUIRE(p.isTerrainCharge()==false);
}

TEST_CASE("[programme] Le chargement du fichier fonctionne")
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

TEST_CASE("[programme] Le robot est correctement initialise")
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
    REQUIRE_EQ(r.getPositionActuelle().getX(),0);
    REQUIRE_EQ(r.getPositionActuelle().getY(),2);
    REQUIRE_EQ(r.nombreObservateurs(),4);
    remove(fichierTerrain.c_str());

}

class fakeProgramme : public programme{
public:
    bool algorithmeMainDroiteExecute=false;
    bool algorithmePledgeExecute=false;
    bool AffichageSimpleExecute=false;
    bool AffichageAmeliore1Execute=false;
    bool AffichageAmeliore2Execute=false;

    void choisirAlgorithme(robot &r,int choix)
    {
        if (choix == 1) {
            algorithmeMainDroiteExecute=true;
        } else if (choix == 2) {
            algorithmePledgeExecute=true;
        }
    };
    void choisirAffichage(int choix)
    {
        if (choix == 1)
        {
            AffichageSimpleExecute=true;
        }
        else if (choix == 2)
        {
            AffichageAmeliore1Execute=true;
        }
        else if (choix == 3)
        {
            AffichageAmeliore2Execute=true;
        }
    }

};

TEST_CASE("[programme] Le programme execute l'algorithme choisi")
{
    robot r;
    fakeProgramme p;
    SUBCASE("si l'utilisateur choisi l'algorithme main droite")
    {
        int choix=1;
        p.choisirAlgorithme(r,choix);
        REQUIRE(p.algorithmeMainDroiteExecute==true);
    }
    SUBCASE("si l'utilisateur choisi l'algorithme Pledge")
    {
        int choix=2;
        p.choisirAlgorithme(r,choix);
        REQUIRE(p.algorithmePledgeExecute==true);
    }
    SUBCASE("si l'utilisateur saisit une autre valeur")
    {
        int choix=3;
        p.choisirAlgorithme(r,choix);
        REQUIRE(p.algorithmePledgeExecute==false);
        REQUIRE(p.algorithmeMainDroiteExecute==false);
    }

}

TEST_CASE("[programme] Le programme execute l'affichage choisi")
{
    robot r;
    fakeProgramme p;
    SUBCASE("si l'utilisateur choisi l'affichage simple")
    {
        int choix=1;
        p.choisirAffichage(choix);
        REQUIRE(p.AffichageSimpleExecute==true);
    }
    SUBCASE("si l'utilisateur choisi l'affichage ameliore 1")
    {
        int choix=2;
        p.choisirAffichage(choix);
        REQUIRE(p.AffichageAmeliore1Execute==true);
    }
    SUBCASE("si l'utilisateur choisi l'affichage ameliore 2")
    {
        int choix=3;
        p.choisirAffichage(choix);
        REQUIRE(p.AffichageAmeliore2Execute==true);
    }
    SUBCASE("si l'utilisateur saisit une autre valeur")
    {
        int choix=4;
        p.choisirAffichage(choix);
        REQUIRE(p.AffichageSimpleExecute==false);
        REQUIRE(p.AffichageAmeliore1Execute==false);
        REQUIRE(p.AffichageAmeliore2Execute==false);
    }

}



