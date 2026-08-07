#include "display/render.h"

void render() {
  TuileDepart t(1);
  TuileDisplay dt(&t);
  GardeDuCorps p;
  PlayerDisplay dp(&p);
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

    dt.Display();
    dp.Display();

    window.display();
  }
}
