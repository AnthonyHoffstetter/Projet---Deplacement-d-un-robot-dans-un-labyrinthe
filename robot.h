#ifndef ROBOT_H
#define ROBOT_H

#include "position.h"
#include <vector>

using namespace std;

/**Les fonctions en commentaires ne sont pas encore définissable tant que nous n'avons pas les autres classes */

class robot {
    private:
        position d_position;
        char d_direction;
        //vector<robotObservateur> d_observateurs;
        //terrain d_terrain;

    public:
        //robot(const terrain* &t, const position &pos, char direction);
        position getPositionActuelle() const;
        char getDirection() const;
        //bool detecterObstacleAvant(const terrain& terrain);
        //bool detecterObstacleDroite(const terrain& terrain);
        //void enregistrerObservateur(const robotObservateur &obs);
        void notifierObservateurs();
        void avancer();
        void tournerGauche();
        void tournerDroite();

};

#endif // ROBOT_H
