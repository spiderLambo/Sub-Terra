#include "display/geometry.h"

Rectangle::Rectangle(sf::Vector2f taille, sf::Vector2f position,
                     sf::Color couleur)
    : sf::RectangleShape(taille) {
  setFillColor(couleur);
  setPosition(position);
  window = &::window;
}

Rectangle::~Rectangle() {}

void Rectangle::Display() { (*window).draw(*this); }
