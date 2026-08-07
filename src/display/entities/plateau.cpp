#include "display/entities/plateau.h"

#include <iostream>

TuileDisplay::TuileDisplay(Tuile* tuile, sf::Vector2f position)
    : Rectangle(sf::Vector2f(100.0f, 100.0f), position,
                Str_to_color(tuile->couleur), Str_to_color("#FFFFFF"), 2.0f) {
  this->tuile = tuile;
}
TuileDisplay::~TuileDisplay() {}

PlateauDisplay::PlateauDisplay(Plateau* plateau) { this->plateau = plateau; }
PlateauDisplay::~PlateauDisplay() {}
void PlateauDisplay::Display() {
  for (int i = 0; i < 128; ++i) {
    for (int j = 0; j < 128; ++j) {
      Tuile* t = plateau->getTuile(i, j);

      if (t != nullptr) {
        TuileDisplay td(t, sf::Vector2f(j * 102, i * 102));
        td.Display();
        PlayerList players = plateau->getPlayersOnTuile(t);
        players.Display(j * 102, i * 102);
      }
    }
  }
}