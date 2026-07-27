#include "tuiles/tuile.h"

TuileDepart::TuileDepart(int id) : Tuile(id, DEPART, {true, true, true, true}, "#17540F") { }

void TuileDepart::effetTuile(enum Evenement evenement, std::array<Player*, 4> players) { return; }
