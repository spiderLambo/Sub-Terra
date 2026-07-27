#include "tuiles/tuile.h"

TuileTerrainAccidente::TuileTerrainAccidente(int id, std::array<bool, 4> acces) : Tuile(id, TERRAIN_ACCIDENTE, acces, "#F1FF00") { }

void TuileTerrainAccidente::effetTuile(enum Evenement evenement, std::array<Player*, 4> players) {
  // TODO:
  return;
}
