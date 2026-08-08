#include "display/scenes/scene.h"

Scene::Scene() : window(&::window) {}
Scene::~Scene() {}
void Scene::afficher() {}

void Scene::events() {
  while (window->pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window->close();
    }
    if (event.type == sf::Event::GainedFocus) {
      window->setPosition(sf::Vector2i(0, 0));
    }
  }
}

void Scene::Display() {
  while (window->isOpen()) {
    events();

    window->clear();

    afficher();

    window->display();
  }
}
