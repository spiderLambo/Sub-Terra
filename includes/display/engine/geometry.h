#pragma once
#include <SFML/Graphics.hpp>

#include "display/engine/window.h"

class Rectangle : public sf::RectangleShape {
 protected:
  Window* window;

 public:
  Rectangle(sf::Vector2f taille, sf::Vector2f position,
            sf::Color couleur = sf::Color::Transparent,
            sf::Color outline = sf::Color::Transparent,
            float outlineSize = 0.0f);

  ~Rectangle();
  void Display();
};

class Circle : public sf::CircleShape {
 protected:
  Window* window;

 public:
  Circle(float taille, sf::Vector2f position,
         sf::Color couleur = sf::Color::Transparent,
         sf::Color outline = sf::Color::Transparent, float outlineSize = 0.0f);

  ~Circle();
  void Display();
};