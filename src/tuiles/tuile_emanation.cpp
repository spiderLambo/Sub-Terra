#include "tuiles/tuile.h"

TuileEmanation::TuileEmanation(int id, std::array<bool, 4> acces) : Tuile(id, EMANATION, acces, "#50FF3D") { }

void TuileEmanation::effetTuile(enum Evenement evenement, std::array<Player*, 4> players) {
  // TODO:
  return;
}
