#include "display/entities/plateau.h"

TuileDisplay::TuileDisplay(Tuile* tuile, sf::Vector2f position, int size)
    : Rectangle(sf::Vector2f(size, size), position,
                Str_to_color(tuile->couleur)) {
  this->tuile = tuile;
  this->size = size;
}
TuileDisplay::~TuileDisplay() {}
void TuileDisplay::Display() {
  std::array<unsigned int, 4> acces;
  for (int i = 0; i < 4; ++i) {
    acces[i] = !this->tuile->getAcces(i) ? 1 : 0;
  }

  Rectangle r1(
      sf::Vector2f(size / 4 + size * 3 / 4 * acces[0], size / 4),
      sf::Vector2f(this->getPosition().x - 2, this->getPosition().y - 2),
      Str_to_color("#FFFFFF"));
  Rectangle r2(sf::Vector2f(size / 4, size / 4 + size * 3 / 4 * acces[1]),
               sf::Vector2f(this->getPosition().x + size * 3 / 4 + 2,
                            this->getPosition().y - 2),
               Str_to_color("#FFFFFF"));
  Rectangle r3(sf::Vector2f(size / 4 + size * 3 / 4 * acces[2], size / 4),
               sf::Vector2f(this->getPosition().x + size * 3 / 4 -
                                size * 3 / 4 * acces[2] + 2,
                            this->getPosition().y + size * 3 / 4 + 2),
               Str_to_color("#FFFFFF"));
  Rectangle r4(sf::Vector2f(size / 4, size / 4 + size * 3 / 4 * acces[3]),
               sf::Vector2f(this->getPosition().x - 2,
                            this->getPosition().y + size * 3 / 4 -
                                size * 3 / 4 * acces[3] + 2),
               Str_to_color("#FFFFFF"));

  r1.Display();
  r2.Display();
  r3.Display();
  r4.Display();
  Rectangle::Display();
}

PlateauDisplay::PlateauDisplay(Plateau* plateau) { this->plateau = plateau; }
PlateauDisplay::~PlateauDisplay() {}
void PlateauDisplay::Display(int x, int y, int& tuileSize) {
  std::pair<std::pair<int, int>, std::pair<int, int>> dim =
      plateau->getDimensions();

  if (tuileSize == -1) {
    tuileSize = static_cast<int>(
        std::min((0.7f * ::window.Width() - 22) /
                     (dim.second.second - dim.first.second + 1),
                 (::window.Height() - 70.0f) /
                     (dim.second.first - dim.first.first + 1)));
    tuileSize = std::min(tuileSize, 100);
  }

  for (int i = dim.first.first; i <= dim.second.first; ++i) {
    for (int j = dim.first.second; j <= dim.second.second; ++j) {
      Tuile* t = plateau->getTuile(i, j);

      std::pair<unsigned int, unsigned int> coordones(
          (j - dim.first.second) * (tuileSize + 2) + x + 2,
          (i - dim.first.first) * (tuileSize + 2) + y + 2);

      if (t != nullptr) {
        TuileDisplay td(t, sf::Vector2f(coordones.first, coordones.second),
                        tuileSize);
        td.Display();
        PlayerList players = plateau->getPlayersOnTuile(t);
        players.Display(coordones.first, coordones.second);
      }
    }
  }
}