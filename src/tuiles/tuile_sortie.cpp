#include "tuiles/tuile.h"

TuileSortie::TuileSortie(int id) : Tuile(id, SORTIE, {true, false, false, false}, "#B00000") { }

void TuileSortie::effetTuile(enum Evenement evenement, std::array<Player*, 4> players) { return; }
