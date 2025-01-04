#ifndef CALCUL_TEMPS_H
#define CALCUL_TEMPS_H

#include "observateur.h"
#include <chrono>
#include <iostream>

/**
 * Classe pour calculer le temps écoulé entre les mouvements du robot.
 */
class calcul_temps : public observateur {
private:
    std::chrono::steady_clock::time_point d_debut;
    std::chrono::steady_clock::time_point d_dernierUpdate;

public:
    calcul_temps();
    void update(const robot &r) override;
    virtual void afficherStatistique() override;
};

#endif // CALCUL_TEMPS_H
