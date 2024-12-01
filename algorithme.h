#ifndef ALGORITHME_H
#define ALGORITHME_H

#include "robot.h"
#include "terrain.h"

class algorithme
{
public:
    virtual ~algorithme()=default;
    virtual void executer(robot &r, const terrain &t)=0;

};

#endif // ALGORITHME_H
