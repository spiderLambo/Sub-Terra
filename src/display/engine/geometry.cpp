#include "display/engine/geometry.h"

Rectangle::Rectangle(sf::Vector2f taille, sf::Vector2f position,
                     sf::Color couleur, sf::Color outline)
    : sf::RectangleShape(taille) {
  setFillColor(couleur);
  setPosition(position);
  setOutlineColor(outline);
  setOutlineThickness(2.0f);
  window = &::window;
}

Rectangle::~Rectangle() { delete window; }

void Rectangle::Display() { (*window).draw(*this); }
