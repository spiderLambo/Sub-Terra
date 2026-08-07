#include "display/entities/tuile.h"

TuileDisplay::TuileDisplay(Tuile* tuile, sf::Vector2f position)
    : Rectangle(sf::Vector2f(100.0f, 100.0f), position,
                Str_to_color(tuile->couleur), Str_to_color("#FFFFFF"), 2.0f) {
  this->tuile = tuile;
}

TuileDisplay::~TuileDisplay() { delete tuile; }