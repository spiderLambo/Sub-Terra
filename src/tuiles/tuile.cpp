#include "tuiles/tuile.h"

Tuile::Tuile(int id, enum TuileType type, std::array<bool, 4> acces, std::string couleur) {
  this->id = id;
  this->type = type;
  this->acces = acces;
  this->couleur = couleur;
}

Tuile::rotation() {
  bool temp = acces[3];
  for (int i = 3; i > 0; i--) {
    acces[i] = acces[i - 1];
  }
  acces[0] = temp;
}

Tuile::getAcces(int direction, Player* player) {
  return acces[direction];
}

TuileDepart::TuileDepart(int id) : Tuile(id, DEPART, {true, true, true, true}, "#17540F") { }

TuileSortie::TuileSortie(int id) : Tuile(id, SORTIE, {true, false, false, false}, "#B00000") { }

TuileOrdinaire::TuileOrdinaire(int id, std::array<int, 4> acces) : Tuile(id, ORDINAIRE, acces, "#696969") { }

TuileOrdinaire::TuileOrdinaire(int id, std::array<int, 4> acces) : Tuile(id, INONDABLE, acces, "#5CD6D0") { }

TuileOrdinaire::TuileOrdinaire(int id, std::array<int, 4> acces) : Tuile(id, EMANATION, acces, "#50FF3D") { }

TuileOrdinaire::TuileOrdinaire(int id, std::array<int, 4> acces) : Tuile(id, EFFONDREMENT, acces, "#594609") { }

TuileOrdinaire::TuileOrdinaire(int id, std::array<int, 4> acces) : Tuile(id, HORREUR, acces, "#000000") { }

TuileOrdinaire::TuileOrdinaire(int id, std::array<int, 4> acces) : Tuile(id, RETRECISSEMENT, acces, "#FFC003") { }

TuileOrdinaire::TuileOrdinaire(int id, std::array<int, 4> acces) : Tuile(id, CORNICHE, acces, "#E78AFF") { }

TuileOrdinaire::TuileOrdinaire(int id, std::array<int, 4> acces) : Tuile(id, CHUTE, acces, "#BD8AFF") { }

TuileOrdinaire::TuileOrdinaire(int id, std::array<int, 4> acces) : Tuile(id, TERRAIN_ACCIDENTE, acces, "#F1FF00") { }
