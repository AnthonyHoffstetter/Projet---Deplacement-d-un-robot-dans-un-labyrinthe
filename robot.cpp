#include "robot.h"


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
        case 'E':
            d_direction='N';
        case 'S':
            d_direction='E';
        case 'O':
            d_direction='S';
    }
}


void robot::tournerDroite()
{
    switch (d_direction) {
        case 'N':
            d_direction='E';
        case 'E':
            d_direction='S';
        case 'S':
            d_direction='O';
        case 'O':
            d_direction='N';
    }
}

