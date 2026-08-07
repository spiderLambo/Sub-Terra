#include "utils/Str_to_color.h"

sf::Color Str_to_color(std::string hex) {
  std::string h = hex.substr(1);
  int r = std::stoi(h.substr(0, 2), nullptr, 16);
  int g = std::stoi(h.substr(2, 2), nullptr, 16);
  int b = std::stoi(h.substr(4, 2), nullptr, 16);
  return sf::Color(r, g, b);
}