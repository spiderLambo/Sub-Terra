#include "tuiles/tuile.h"

TuileRetrecissement::TuileRetrecissement(int id, std::array<bool, 4> acces) : Tuile(id, RETRECISSEMENT, acces, "#FFC003") { }

void TuileRetrecissement::effetTuile(enum Evenement evenement, std::array<Player*, 4> players) { return; }
