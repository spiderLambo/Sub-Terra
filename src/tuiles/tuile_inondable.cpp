#include "tuiles/tuile.h"

TuileInondable::TuileInondable(int id, std::array<bool, 4> acces) : Tuile(id, INONDABLE, acces, "#5CD6D0") { }

void TuileInondable::effetTuile(std::array<Player*, 6> players) {
  inondee = true;
  bool gardeDuCorps = false;
  for (int i = 0; i < 6; i++) {
    if (players[i] != nullptr && players[i]->getRang() == 7) {
      gardeDuCorps = true;
    }
  }
  for (int i = 0; i < 6; i++) {
    if (players[i] != nullptr && players[i]->getRang() != 1) {
      if (!gardeDuCorps || players[i]->getRang() == 7) {
        players[i]->subirDegats(1);
      }
    }
  }
}
