#include "display/engine/window.h"

Window::Window() {
  sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
  create(sf::VideoMode(desktopMode.width, desktopMode.height - 40), "Sub Terra",
         sf::Style::Titlebar | sf::Style::Close);

  setSize(sf::Vector2u(desktopMode.width, desktopMode.height - 40));
  setPosition(sf::Vector2i(0, 0));
  setFramerateLimit(60);
  width = desktopMode.width;
  height = desktopMode.height - 40;
}

Window::~Window() {}

int Window::Height() { return height; }
int Window::Width() { return width; }

Window window;