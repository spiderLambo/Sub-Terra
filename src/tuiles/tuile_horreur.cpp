#include "tuiles/tuile.h"

TuileHorreur::TuileHorreur(int id, std::array<bool, 4> acces) : Tuile(id, HORREUR, acces, "#000000") { }

void TuileHorreur::effetTuile(std::array<Player*, 6> players) {
  // spawn horreur
  for (int i = 0; i < 6; i++) {
    if (players[i]->getRang() != 2) {
      players[i]->subirDegats(players[i]->getPv());
    }
  }
}
