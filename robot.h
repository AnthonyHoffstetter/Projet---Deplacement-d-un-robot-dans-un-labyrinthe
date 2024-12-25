#ifndef ROBOT_H
#define ROBOT_H

#include "position.h"
#include <vector>
#include "terrain.h"
#include "observateur.h"
#include <memory>

using namespace std;


class robot {
    private:
        position d_position;
        position d_anciennePosition;
        char d_direction;
        vector<unique_ptr<observateur>> d_observateurs;

    public:
        robot(const position &pos, char direction);
        position getPositionActuelle() const;
        position getAnciennePosition() const;
        char getDirection() const;
        bool detecterObstacleDevant(const terrain& terrain);
        bool detecterObstacleDroite(const terrain& terrain);
        void enregistrerObservateur(std::unique_ptr<observateur> obs);
        void notifierObservateurs();
        void avancer();
        void tournerGauche();
        void tournerDroite();

};

#endif // ROBOT_H
