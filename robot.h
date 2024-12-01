#ifndef ROBOT_H
#define ROBOT_H

#include "position.h"
#include <vector>
#include "terrain.h"

using namespace std;

/**Faire les tests unitaires de cette classe */

class robot {
    private:
        position d_position;
        char d_direction;
        //vector<robotObservateur> d_observateurs;

    public:
        robot(const position &pos, char direction);
        position getPositionActuelle() const;
        char getDirection() const;
        bool detecterObstacleDevant(const terrain& terrain);
        bool detecterObstacleDroite(const terrain& terrain);
        //void enregistrerObservateur(const robotObservateur &obs);
        void notifierObservateurs();
        void avancer();
        void tournerGauche();
        void tournerDroite();

};

#endif // ROBOT_H
