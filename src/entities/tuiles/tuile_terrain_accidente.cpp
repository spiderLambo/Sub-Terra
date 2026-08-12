#include "entities/tuiles/tuile.h"

TuileTerrainAccidente::TuileTerrainAccidente(int id, std::array<bool, 4> acces) : Tuile(id, TERRAIN_ACCIDENTE, acces, "#F1FF00") { }

void TuileTerrainAccidente::effetArriveeJoueur(Player* player) {
  // vérification RNG
  player->subirDegats(1);
}
