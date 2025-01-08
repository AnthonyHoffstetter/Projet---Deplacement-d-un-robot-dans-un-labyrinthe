#ifndef COMPTEUR_ROTATION_H
#define COMPTEUR_ROTATION_H

#include "observateur.h"
#include "robot.h"


class compteur_rotation : public observateur {
private:
    int nombreRotations;
    char ancienneDirection;

public:
    compteur_rotation(char direction);
    int getNombreRotations() const;
    void reset();
    void update(const robot& r) override;
    virtual void afficherStatistique() override;
};

#endif // COMPTEUR_ROTATION_H
