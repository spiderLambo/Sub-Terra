#include "tuiles/tuile.h"

TuileHorreur::TuileHorreur(int id, std::array<bool, 4> acces) : Tuile(id, HORREUR, acces, "#000000") { }

void TuileHorreur::effetTuile(enum Evenement evenement, std::array<Player*, 4> players) {
  // TODO:
  return;
}
