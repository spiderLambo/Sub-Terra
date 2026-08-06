#include "display/render.h"

void render() {
  sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
  sf::RenderWindow window(
      sf::VideoMode(desktopMode.width, desktopMode.height - 40), "Sub Terra",
      sf::Style::Titlebar | sf::Style::Close);

  window.setSize(sf::Vector2u(desktopMode.width, desktopMode.height - 40));
  window.setPosition(sf::Vector2i(0, 0));

  window.setFramerateLimit(60);

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
    window.display();
  }
}
