#pragma once
#include <SFML/Graphics.hpp>

class Window : public sf::RenderWindow {
 private:
  int height;
  int width;

 public:
  Window();
  ~Window();

  int Height();
  int Width();
};

extern Window window;