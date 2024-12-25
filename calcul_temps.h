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
    // Constructeur
    calcul_temps();

    // Méthode appelée lorsque le robot se déplace
    void update(const robot &r) override;

    // Méthode pour afficher le temps écoulé total
    void afficherTempsTotal() const;
};

#endif // CALCUL_TEMPS_H
