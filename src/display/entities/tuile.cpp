#include "display/entities/tuile.h"

TuileDisplay::TuileDisplay(Tuile* tuile)
    : Rectangle(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(50.0f, 50.0f),
                Str_to_color(tuile->couleur)) {
  this->tuile = tuile;
}

TuileDisplay::~TuileDisplay() { delete tuile; }