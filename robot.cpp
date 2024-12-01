#include "robot.h"
#include <iostream>

robot::robot(const position &pos, char direction):
    d_position{pos},d_direction{direction}
{}

position robot::getPositionActuelle() const
{
    return d_position;
}


char robot::getDirection() const
{
    return d_direction;
}


/*void robot::notifierObservateurs()
{
    for(int i=0;i<d_observateurs.size();i++)
    {
        d_observateurs[i].update();
    }
}*/


void robot::avancer()
{
    /*if (detecterObstacleAvant()) {
        std::cout << "Obstacle détecté devant. Impossible d'avancer !" << std::endl;
        return;
    }*/
    switch (d_direction) {
        case 'N':
            d_position.setPosition(d_position.getX()-1, d_position.getY());
        case 'E':
            d_position.setPosition(d_position.getX(), d_position.getY()+1);
        case 'S':
            d_position.setPosition(d_position.getX()+1, d_position.getY());
        case 'O':
            d_position.setPosition(d_position.getX(), d_position.getY()-1);
    }
}


void robot::tournerGauche()
{
    switch (d_direction) {
        case 'N':
            d_direction='O';
            break;
        case 'E':
            d_direction='N';
            break;
        case 'S':
            d_direction='E';
            break;
        case 'O':
            d_direction='S';
            break;
    }
}


void robot::tournerDroite()
{
    switch (d_direction) {
        case 'N':
            d_direction='E';
            break;
        case 'E':
            d_direction='S';
            break;
        case 'S':
            d_direction='O';
            break;
        case 'O':
            d_direction='N';
            break;
    }
}

// ?

