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

void robot::enregistrerObservateur(std::unique_ptr<observateur> obs)
{
        d_observateurs.push_back(std::move(obs));
}

void robot::notifierObservateurs()
{
    for(int i=0;i<d_observateurs.size();i++)
    {
        d_observateurs[i]->update(*this);
    }
}


void robot::avancer()
{
    switch (d_direction) {
        case 'N':
            d_position.setPosition(d_position.getX(), d_position.getY()-1);
            break;
        case 'E':
            d_position.setPosition(d_position.getX()+1, d_position.getY());
            break;
        case 'S':
            d_position.setPosition(d_position.getX(), d_position.getY()+1);
            break;
        case 'O':
            d_position.setPosition(d_position.getX()-1, d_position.getY());
            break;
    }
    notifierObservateurs();
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
    notifierObservateurs();
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
    notifierObservateurs();
}

bool robot::detecterObstacleDevant(const terrain& terrain)
{
    position posDevant{};
    switch (d_direction)
    {
        case 'N':
            posDevant.setPosition(d_position.getX(), d_position.getY()-1);
            break;
        case 'E':
            posDevant.setPosition(d_position.getX()+1, d_position.getY());
            break;
        case 'S':
            posDevant.setPosition(d_position.getX(), d_position.getY()+1);
            break;
        case 'O':
            posDevant.setPosition(d_position.getX()-1, d_position.getY());
            break;
    }

    return !terrain.estLibre(posDevant);
}


bool robot::detecterObstacleDroite(const terrain& terrain)
{
    position posDroite{};
    switch (d_direction)
    {
        case 'N':
            posDroite.setPosition(d_position.getX()+1, d_position.getY());
            break;
        case 'E':
            posDroite.setPosition(d_position.getX(), d_position.getY()+1);
            break;
        case 'S':
            posDroite.setPosition(d_position.getX()-1, d_position.getY());
            break;
        case 'O':
            posDroite.setPosition(d_position.getX(), d_position.getY()-1);
            break;
    }

    return !terrain.estLibre(posDroite);
}

