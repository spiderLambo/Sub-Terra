#include "display/render.h"

void render() {
  TuileDepart t(1);
  float positionst = 10.0f;
  float positionsp = 10.0f;
  TuileDisplay dt(&t, sf::Vector2f(positionst, positionst));
  GardeDuCorps p;
  PlayerDisplay dp(&p, sf::Vector2f(positionsp, positionsp));
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

    positionst += 0.5;
    positionsp += 1;
    dp.setPosition(sf::Vector2f(positionsp, positionsp));
    dt.setPosition(sf::Vector2f(positionst, positionst));

    dt.Display();
    dp.Display();

    window.display();
  }
}
