#pragma once

#include "display/engine/window.h"

class Texte : public sf::Text {
 private:
  std::string text;
  sf::Vector2f position;
  sf::Font font;
  Window* window;

 public:
  Texte(std::string text, sf::Vector2f position);
  ~Texte();
  void Display();
};