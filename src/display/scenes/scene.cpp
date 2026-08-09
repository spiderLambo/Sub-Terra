#include "display/scenes/scene.h"

Scene::Scene() : window(&::window) {}
Scene::~Scene() {}
void Scene::afficher() {}

void Scene::events() {
  if (event.type == sf::Event::Closed) {
    window->close();
  }
  if (event.type == sf::Event::GainedFocus) {
    window->setPosition(sf::Vector2i(0, 0));
  }
}

void Scene::view(std::pair<float, float> size, std::pair<float, float> position,
                 std::function<void()> display) {
  sf::View vue(sf::FloatRect(0.0f, 0.0f, size.first, size.second));

  vue.setViewport(sf::FloatRect(
      position.first / windowWidth, position.second / windowHeight,
      size.first / windowWidth, size.second / windowHeight));

  window->setView(vue);
  display();

  window->setView(window->getDefaultView());
}

void Scene::Display() {
  while (window->isOpen()) {
    while (window->pollEvent(event)) {
      events();
    }

    window->clear();

    afficher();

    window->display();
  }
}
