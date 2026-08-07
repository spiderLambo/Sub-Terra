#include "display/render.h"

void render() {
  TuileDepart t(1);
  TuileDisplay d(&t);
  Circle c(100.0f, sf::Vector2f(300.0f, 500.0f), sf::Color::Red,
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

    d.Display();
    c.Display();

    window.display();
  }
}
