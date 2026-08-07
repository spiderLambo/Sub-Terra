#include "display/render.h"

void render() {
  Rectangle r(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(50.0f, 50.0f),
              sf::Color::Blue);
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      if (event.type == sf::Event::GainedFocus) {
        window.setPosition(sf::Vector2i(0, 0));
      }
    }

    window.clear();
    r.Display();
    window.display();
  }
}
