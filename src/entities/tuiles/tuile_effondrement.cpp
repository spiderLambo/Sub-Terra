#include "entities/tuiles/tuile.h"

TuileEffondrement::TuileEffondrement(int id, std::array<bool, 4> acces, std::pair<int,int> numEboulement) : Tuile(id, EFFONDREMENT, acces, "#594609") {
  this->numEboulement = numEboulement;
}

void TuileEffondrement::effetTuile(std::array<Player*, 6> players, int nbEboulement) {
  if (numEboulement.first != nbEboulement && numEboulement.second != nbEboulement) return;
  effondre = true;
  bool gardeDuCorps = false;
  for (int i = 0; i < 6; i++) {
    if (players[i] != nullptr && players[i]->getRang() == 7) {
      gardeDuCorps = true;
    }
  }
  for (int i = 0; i < 6; i++) {
    if (players[i] != nullptr) {
      if (!gardeDuCorps || players[i]->getRang() == 7) {
        if (players[i]->getRang() == 4) players[i]->subirDegats(1);
        else players[i]->subirDegats(3);
      }
    }
  }
}

void TuileEffondrement::effetActionJoueur(Player* player) {
  // vérification RNG
  effondre = false;
}

bool TuileEffondrement::getAcces(int direction, Player* player) {
  return !effondre && acces[direction];
}
