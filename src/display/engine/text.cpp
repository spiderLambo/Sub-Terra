#include "display/engine/text.h"

Texte::Texte(std::string text, sf::Vector2f position) {
  if (font.loadFromFile(
          "/usr/share/fonts/truetype/andika/Andika-Regular.ttf")) {
    setFont(font);
    setString(text);
    setPosition(position);
    window = &::window;
  }
}
Texte::~Texte() {}
void Texte::Display() { (*window).draw(*this); }