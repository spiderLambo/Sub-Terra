#include "tuiles/tuile.h"

TuileEffondrement::TuileEffondrement(int id, std::array<bool, 4> acces, std::pair<int,int> numEboulement) : Tuile(id, EFFONDREMENT, acces, "#594609") {
  this->numEboulement = numEboulement;
}

void TuileEffondrement::effetTuile(enum Evenement evenement, std::array<Player*, 4> players) {
  bool gardeDuCorps = false;
  switch (evenement) {
    case ACTION_JOUEUR:
      // vérification RNG
      effondre = false;
      break;
    case EBOULEMENT:
      // vérification RNG numEboulement
      effondre = true;
      for (int i = 0; i < 4; i++) {
        if (players[i] != nullptr && players[i]->getRang() == 7) {
          gardeDuCorps = true;
        }
      }
      for (int i = 0; i < 4; i++) {
        if (players[i] != nullptr) {
          if (!gardeDuCorps || players[i]->getRang() == 7) {
            players[i]->subirDegats(3);
          }
        }
      }
      break;
    default:
      break;
  }
}

bool TuileEffondrement::getAcces(int direction, Player* player) {
  return !effondre && acces[direction];
}
