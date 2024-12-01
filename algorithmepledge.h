#ifndef ALGORITHMEPLEDGE_H
#define ALGORITHMEPLEDGE_H
#include "algorithme.h"

class algorithmePledge : public algorithme
{
    public:
        void executer(robot &r, const terrain &t) override;
};

#endif // ALGORITHMEPLEDGE_H
