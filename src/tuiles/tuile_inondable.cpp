#include "tuiles/tuile.h"

TuileInondable::TuileInondable(int id, std::array<bool, 4> acces) : Tuile(id, INONDABLE, acces, "#5CD6D0") { }

void TuileInondable::effetTuile(enum Evenement evenement, std::array<Player*, 4> players) {
  // TODO:
  return;
}
