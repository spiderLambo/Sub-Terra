#include <functional>

#include "display/engine/window.h"

class Scene {
 private:
  Window* window;

  virtual void afficher();

 protected:
  sf::Event event;

  const int windowWidth = window->Width();
  const int windowHeight = window->Height();

  virtual void events();

  void view(std::pair<float, float> size, std::pair<float, float> position,
            std::function<void()> display);

 public:
  Scene();
  virtual ~Scene() = 0;

  void Display();
};