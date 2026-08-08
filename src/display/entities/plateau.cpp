#include "display/entities/plateau.h"

#include <iostream>

TuileDisplay::TuileDisplay(Tuile* tuile, sf::Vector2f position)
    : Rectangle(sf::Vector2f(100.0f, 100.0f), position,
                Str_to_color(tuile->couleur)) {
  this->tuile = tuile;
}
TuileDisplay::~TuileDisplay() {}
void TuileDisplay::Display() {
  std::array<unsigned int, 4> acces;
  for (int i = 0; i < 4; ++i) {
    acces[i] = !this->tuile->getAcces(i) ? 1 : 0;
  }

  Rectangle r1(
      sf::Vector2f(25.0f + 75 * acces[0], 25.0f),
      sf::Vector2f(this->getPosition().x - 2, this->getPosition().y - 2),
      Str_to_color("#FFFFFF"));
  Rectangle r2(
      sf::Vector2f(25.0f, 25.0f + 75 * acces[1]),
      sf::Vector2f(this->getPosition().x + 77, this->getPosition().y - 2),
      Str_to_color("#FFFFFF"));
  Rectangle r3(sf::Vector2f(25.0f + 75 * acces[1], 25.0f),
               sf::Vector2f(this->getPosition().x + 77 - 75 * acces[1],
                            this->getPosition().y + 77),
               Str_to_color("#FFFFFF"));
  Rectangle r4(sf::Vector2f(25.0f, 25.0f + 75 * acces[1]),
               sf::Vector2f(this->getPosition().x - 2,
                            this->getPosition().y + 77 - 75 * acces[1]),
               Str_to_color("#FFFFFF"));

  r1.Display();
  r2.Display();
  r3.Display();
  r4.Display();
  Rectangle::Display();
}

PlateauDisplay::PlateauDisplay(Plateau* plateau) { this->plateau = plateau; }
PlateauDisplay::~PlateauDisplay() {}
void PlateauDisplay::Display(int x, int y) {
  std::pair<std::pair<int, int>, std::pair<int, int>> dim =
      plateau->getDimensions();
  for (int i = dim.first.first; i <= dim.second.first; ++i) {
    for (int j = dim.first.second; j <= dim.second.first; ++j) {
      Tuile* t = plateau->getTuile(i, j);

      std::pair<unsigned int, unsigned int> coordones(
          (j - dim.first.second) * 102 + x, (i - dim.first.first) * 102 + y);
      if (t != nullptr) {
        TuileDisplay td(t, sf::Vector2f(coordones.first, coordones.second));
        td.Display();
        PlayerList players = plateau->getPlayersOnTuile(t);
        players.Display(coordones.first, coordones.second);
      }
    }
  }
}