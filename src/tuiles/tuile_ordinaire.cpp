#include "tuiles/tuile.h"

TuileOrdinaire::TuileOrdinaire(int id, std::array<bool, 4> acces) : Tuile(id, ORDINAIRE, acces, "#696969") { }

void TuileOrdinaire::effetTuile(enum Evenement evenement, std::array<Player*, 4> players) { return; }

