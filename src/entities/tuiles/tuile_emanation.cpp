#include "entities/tuiles/tuile.h"

TuileEmanation::TuileEmanation(int id, std::array<bool, 4> acces) : Tuile(id, EMANATION, acces, "#50FF3D") { }

void TuileEmanation::effetTuile(std::array<Player*, 6> players, int nbEboulement) {
  toxique = true;
  for (int i = 0; i < 6; i++) {
    if (players[i] != nullptr) {
      if (!gardeDuCorps || players[i]->getRang() == 7) {
        players[i]->subirDegats(2);
      }
    }
  }
}

void TuileEmanation::effetArriveeJoueur(Player* player) {
  if (player->getRang() == 7) {
    gardeDuCorps = true;
  }
  if (toxique) {
    if (!gardeDuCorps || player->getRang() == 7) player->subirDegats(2);
  }
}

void TuileEmanation::effetSortieJoueur(Player* player) {
  if (player->getRang() == 7) gardeDuCorps = false;
}
