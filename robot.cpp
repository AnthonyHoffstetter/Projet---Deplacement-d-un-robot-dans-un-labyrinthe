#include "robot.h"
#include <iostream>

robot::robot():
    d_position{position()},d_anciennePosition{position()},d_direction{'v'}
{}

robot::robot(const position &pos, char direction):
    d_position{pos},d_anciennePosition{pos},d_direction{direction}
{}

position robot::getPositionActuelle() const
{
    return d_position;
}

position robot::getAnciennePosition() const
{
    return d_anciennePosition;
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
    for(int i=0;i<nombreObservateurs();i++)
    {
        d_observateurs[i]->update(*this);
    }
}


void robot::avancer()
{
    d_anciennePosition=d_position;
    switch (d_direction) {
        case '^':
            d_position.setPosition(d_position.getX(), d_position.getY()-1);
            break;
        case '>':
            d_position.setPosition(d_position.getX()+1, d_position.getY());
            break;
        case 'v':
            d_position.setPosition(d_position.getX(), d_position.getY()+1);
            break;
        case '<':
            d_position.setPosition(d_position.getX()-1, d_position.getY());
            break;
    }
    notifierObservateurs();
}


void robot::tournerGauche()
{
    switch (d_direction) {
        case '^':
            d_direction='<';
            break;
        case '>':
            d_direction='^';
            break;
        case 'v':
            d_direction='>';
            break;
        case '<':
            d_direction='v';
            break;
    }
    notifierObservateurs();
}


void robot::tournerDroite()
{
    switch (d_direction) {
        case '^':
            d_direction='>';
            break;
        case '>':
            d_direction='v';
            break;
        case 'v':
            d_direction='<';
            break;
        case '<':
            d_direction='^';
            break;
    }
    notifierObservateurs();
}

bool robot::detecterObstacleDevant(const terrain& terrain)
{
    position posDevant{};
    switch (d_direction)
    {
        case '^':
            posDevant.setPosition(d_position.getX(), d_position.getY()-1);
            break;
        case '>':
            posDevant.setPosition(d_position.getX()+1, d_position.getY());
            break;
        case 'v':
            posDevant.setPosition(d_position.getX(), d_position.getY()+1);
            break;
        case '<':
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
        case '^':
            posDroite.setPosition(d_position.getX()+1, d_position.getY());
            break;
        case '>':
            posDroite.setPosition(d_position.getX(), d_position.getY()+1);
            break;
        case 'v':
            posDroite.setPosition(d_position.getX()-1, d_position.getY());
            break;
        case '<':
            posDroite.setPosition(d_position.getX(), d_position.getY()-1);
            break;
    }

    return !terrain.estLibre(posDroite);
}

void robot::afficherStatistiquesObservateurs()
{
    for(int i=0;i<nombreObservateurs();i++)
    {
        d_observateurs[i]->afficherStatistique();
    }
}

void robot::setPosition(const position &p)
{
    d_anciennePosition=d_position;
    d_position=p;
}

int robot::nombreObservateurs() const
{
    return d_observateurs.size();
}
