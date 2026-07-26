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

bool Tuile::getAcces(int direction, Player* player) {
  return acces[direction];
}

TuileDepart::TuileDepart(int id) : Tuile(id, DEPART, {true, true, true, true}, "#17540F") { }

TuileSortie::TuileSortie(int id) : Tuile(id, SORTIE, {true, false, false, false}, "#B00000") { }

TuileOrdinaire::TuileOrdinaire(int id, std::array<bool, 4> acces) : Tuile(id, ORDINAIRE, acces, "#696969") { }

TuileInondable::TuileInondable(int id, std::array<bool, 4> acces) : Tuile(id, INONDABLE, acces, "#5CD6D0") { }

TuileEmanation::TuileEmanation(int id, std::array<bool, 4> acces) : Tuile(id, EMANATION, acces, "#50FF3D") { }

TuileEffondrement::TuileEffondrement(int id, std::array<bool, 4> acces) : Tuile(id, EFFONDREMENT, acces, "#594609") { }

TuileHorreur::TuileHorreur(int id, std::array<bool, 4> acces) : Tuile(id, HORREUR, acces, "#000000") { }

TuileRetrecissement::TuileRetrecissement(int id, std::array<bool, 4> acces) : Tuile(id, RETRECISSEMENT, acces, "#FFC003") { }

TuileCorniche::TuileCorniche(int id, std::array<bool, 4> acces) : Tuile(id, CORNICHE, acces, "#E78AFF") { }

TuileChute::TuileChute(int id, std::array<bool, 4> acces) : Tuile(id, CHUTE, acces, "#BD8AFF") { }

TuileTerrainAccidente::TuileTerrainAccidente(int id, std::array<bool, 4> acces) : Tuile(id, TERRAIN_ACCIDENTE, acces, "#F1FF00") { }
