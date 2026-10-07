#include "entities/tuile.h"

TuileTerrainAccidente::TuileTerrainAccidente(int id)
    : Tuile(id, TERRAIN_ACCIDENTE, {true, true, true, true}, "#F1FF00") {}

void TuileTerrainAccidente::effetArriveeJoueur(Player* player) {
  // vérification RNG
  player->subirDegats(1);
}
