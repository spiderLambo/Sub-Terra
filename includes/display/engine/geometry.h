#pragma once
#include <SFML/Graphics.hpp>

#include "display/engine/window.h"

class Rectangle : public sf::RectangleShape {
 private:
  Window* window;

 public:
  Rectangle(sf::Vector2f taille, sf::Vector2f position,
            sf::Color couleur = sf::Color::Transparent,
            sf::Color outline = sf::Color::Transparent);

  ~Rectangle();
  void Display();
};
