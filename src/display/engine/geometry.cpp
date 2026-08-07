#include "display/engine/geometry.h"

Rectangle::Rectangle(sf::Vector2f taille, sf::Vector2f position,
                     sf::Color couleur, sf::Color outline, float outlineSize)
    : sf::RectangleShape(taille) {
  setFillColor(couleur);
  setPosition(position);
  setOutlineColor(outline);
  setOutlineThickness(outlineSize);
  window = &::window;
}
Rectangle::~Rectangle() { delete window; }

void Rectangle::Display() { (*window).draw(*this); }

Circle::Circle(float taille, sf::Vector2f position, sf::Color couleur,
               sf::Color outline, float outlineSize)
    : sf::CircleShape(taille) {
  setFillColor(couleur);
  setPosition(position);
  setOutlineColor(outline);
  setOutlineThickness(outlineSize);
  window = &::window;
}
Circle::~Circle() { delete window; }

void Circle::Display() { (*window).draw(*this); }