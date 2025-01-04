#include "terrain.h"
#include <fstream>
#include <iostream>
#include <windows.h>


using namespace std;

terrain::terrain()
{
    d_terrain.clear();
}

bool terrain::chargerDepuisFichier(const string& nomFichier) {
    ifstream fichier(nomFichier);
    if (!fichier.is_open()) {
        cerr << "Erreur : Impossible d'ouvrir le fichier " << nomFichier << endl;
        return false;
    }

    d_terrain.clear();
    string ligne;
    int y = 0;

    while (getline(fichier, ligne)) {
        vector<char> ligneTerrain;
        for (int x = 0; x < (int)ligne.size(); ++x) {
            char c = ligne[x];
            ligneTerrain.push_back(c);

            if (c == 'D') {
                d_depart.setPosition(x,y);
            } else if (c == 'A') {
                d_arrivee.setPosition(x,y);
            }
        }
        d_terrain.push_back(ligneTerrain);
        ++y;
    }

    d_longueur = d_terrain.size();
    d_largeur = d_terrain.empty() ? 0 : d_terrain[0].size();
    fichier.close();
    return true;
}

void terrain::afficher() const {
    for (const auto& ligne : d_terrain) {
        for (char c : ligne) {
            cout << c;
        }
        cout << endl;
    }
}

void terrain::transformerTexteAmeliore1()
{
    std::vector<std::vector<char>> terrainAmeliore=d_terrain;
    for(int y=0;y<d_longueur;y++)
    {
        for(int x=0;x<d_largeur;x++)
        {
            if(d_terrain[y][x]!='X')
            {
                terrainAmeliore[y][x]=d_terrain[y][x];
            }
            else
            {
                bool murHaut =  y==0 || d_terrain[y-1][x]=='X';
                bool murBas = y==d_longueur-1 || d_terrain[y+1][x]=='X';
                bool murGauche = x==0 || d_terrain[y][x-1]=='X';
                bool murDroite = x==d_largeur-1 || d_terrain[y][x+1]=='X';

                if(murHaut && murBas && murGauche && murDroite)
                {
                    bool angleBasGauche =   x==0 || y==d_longueur-1 || d_terrain[y+1][x-1]=='X';
                    bool angleBasDroite =  x==d_largeur-1 || y==d_longueur-1 || d_terrain[y+1][x+1]=='X';
                    bool angleHautGauche =  y==0 || x==0 || d_terrain[y-1][x-1]=='X';
                    bool angleHautDroite =  y==0 || x==d_largeur-1 || d_terrain[y-1][x+1]=='X';
                    if(angleBasDroite && angleBasGauche && angleHautDroite && angleHautGauche)
                        terrainAmeliore[y][x]='#';
                    else
                        terrainAmeliore[y][x]='+';
                }
                else if(murHaut && murDroite && !murBas && !murGauche || murHaut && murGauche && !murDroite && !murBas || !murHaut && !murGauche && murDroite && murBas || !murHaut && murGauche && !murDroite && murBas )
                    terrainAmeliore[y][x]='+';
                else if(murGauche && murDroite || murDroite && !murHaut && !murBas || murGauche && !murHaut && !murBas)
                    terrainAmeliore[y][x]='-';
                else if(murHaut || murBas)
                    terrainAmeliore[y][x]='|';
                    else
                        terrainAmeliore[y][x]='-';
                }
        }

    }
    d_terrain=terrainAmeliore;
}


void terrain::afficherTexteAmeliore2()
{
    SetConsoleOutputCP(65001);
    for(int y=0;y<d_longueur;y++)
    {
        for(int x=0;x<d_largeur;x++)
        {
            if(d_terrain[y][x]!='#' && d_terrain[y][x]!='-' && d_terrain[y][x]!='+' && d_terrain[y][x]!='|')
            {
                cout<<d_terrain[y][x];
            }
            else if(d_terrain[y][x]=='#')
                cout<<"▄";
            else if(d_terrain[y][x]=='-')
                cout<<"━";
            else if(d_terrain[y][x]=='|')
                cout<<"┃";
            else
            {
                bool murHaut = y>0 && (d_terrain[y-1][x]=='-' || d_terrain[y-1][x]=='+' || d_terrain[y-1][x]=='|');
                bool murBas = y<d_longueur-1 && (d_terrain[y+1][x]=='-' || d_terrain[y+1][x]=='+' || d_terrain[y+1][x]=='|');
                bool murGauche = x>0 && (d_terrain[y][x-1]=='-' || d_terrain[y][x-1]=='+' || d_terrain[y][x-1]=='|');
                bool murDroite = x<d_largeur-1 && (d_terrain[y][x+1]=='-' || d_terrain[y][x+1]=='+' || d_terrain[y][x+1]=='|');
                if(murHaut && murBas && murGauche && murDroite)
                    cout<<"╋";
                else if(murBas && murGauche && murDroite)
                    cout<<"┳";
                else if(murHaut && murGauche && murDroite)
                    cout<<"┻";
                else if(murBas && murHaut && murDroite)
                    cout<<"┣";
                else if(murHaut && murGauche && murBas)
                    cout<<"┫";
                else if(murBas && murDroite)
                    cout<<"┏";
                else if(murHaut && murGauche)
                    cout<<"┛";
                else if(murBas && murGauche)
                    cout<<"┓";
                else if(murHaut && murDroite)
                    cout<<"┗";
                else
                    cout<<'-';

            }
        }
        cout<<endl;
    }

}


int terrain::getLargeur() const {
    return d_largeur;
}

int terrain::getLongueur() const {
    return d_longueur;
}

position terrain::getCaseDepart() const {
    return d_depart;
}

position terrain::getCaseArrivee() const {
    return d_arrivee;
}

bool terrain::estLibre(const position& sp) const {
    int x = sp.getX();
    int y = sp.getY();

    if (x < 0 || x >= d_largeur || y < 0 || y >= d_longueur) {
        return false;
    }

    return d_terrain[y][x] == '.' || d_terrain[y][x] == 'A' || d_terrain[y][x] == 'D';
}
