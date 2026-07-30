#include "tuiles/tuile.h"

TuileCorde::TuileCorde(int id, std::array<bool, 4> acces, int cordeDir, enum TuileType type) : Tuile(id, type, acces, "#BD8AFF") {
  this->cordeDir = cordeDir;
}

void TuileCorde::effetActionJoueur(Player* player) {
  // vérification RNG
  corde = true;
}

bool TuileCorde::getAcces(int direction, Player* player) {
  if (player == nullptr || !acces[direction]) return acces[direction];
  else if (direction == cordeDir && player->getTuileID() == id) return corde;
  return true;
}
