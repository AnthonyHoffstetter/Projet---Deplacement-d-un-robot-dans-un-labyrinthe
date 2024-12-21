#ifndef OBSERVATEUR_H
#define OBSERVATEUR_H

#include "position.h"

class robot;


class observateur {
public:
    virtual ~observateur() = default;

    virtual void update(const robot &r) = 0;
};

#endif // OBSERVATEUR_H
