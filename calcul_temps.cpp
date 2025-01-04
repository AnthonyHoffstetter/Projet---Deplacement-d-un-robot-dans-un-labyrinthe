#include "calcul_temps.h"

calcul_temps::calcul_temps() {
    d_debut = std::chrono::steady_clock::now();
    d_dernierUpdate = d_debut;
}

void calcul_temps::update(const robot &r)
{
    auto maintenant = std::chrono::steady_clock::now();
    d_dernierUpdate = maintenant;


}

void calcul_temps::afficherStatistique()
 {
    auto maintenant = std::chrono::steady_clock::now();
    auto tempsTotal = std::chrono::duration_cast<std::chrono::milliseconds>(maintenant - d_debut).count();

    std::cout << "Temps total ecoule : " << tempsTotal << " ms" << std::endl;
}
