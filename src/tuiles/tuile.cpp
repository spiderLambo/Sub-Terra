#include "tuiles/tuile.h"

Tuile::Tuile(int id, enum TuileType type, std::array<bool, 4> acces, std::string couleur) {
  this->id = id;
  this->type = type;
  this->acces = acces;
  this->couleur = couleur;
}

void Tuile::rotation() {
  bool temp = acces[3];
  for (int i = 3; i > 0; i--) {
    acces[i] = acces[i - 1];
  }
  acces[0] = temp;
}

void effetTuile(std::array<Player*, 6> players) {
  return;
}

void effetArriveeJoueur(Player* player) {
  return;
}

void effetSortieJoueur(Player* player) {
  return;
}

void effetActionJoueur(Player* player) {
  return;
}

bool Tuile::getAcces(int direction, Player* player) {
  return acces[direction];
}

