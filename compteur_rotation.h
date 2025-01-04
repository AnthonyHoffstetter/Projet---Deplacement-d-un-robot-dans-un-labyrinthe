#ifndef COMPTEUR_ROTATION_H
#define COMPTEUR_ROTATION_H

#include "observateur.h"
#include "robot.h"


class compteur_rotation : public observateur {
private:
    int nombreRotations;

public:
    compteur_rotation();

    void reset();
    void update(const robot& r) override;
    virtual void afficherStatistique() override;
};

#endif // COMPTEUR_ROTATION_H
