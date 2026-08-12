#include "entities/tuiles/tuile.h"

TuileCorde::TuileCorde(int id, int cordeDir, enum TuileType type) : Tuile(id, type, {true, false, true, false}, "#BD8AFF") {
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
