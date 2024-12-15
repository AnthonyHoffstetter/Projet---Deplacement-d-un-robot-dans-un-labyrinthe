#ifndef OBSERVATEUR_H
#define OBSERVATEUR_H

#include "position.h"


class observateur {
public:
    virtual ~observateur() = default;

    virtual void update(const position& nouvellePosition, char nouvelleDirection) = 0;
};

#endif // OBSERVATEUR_H
