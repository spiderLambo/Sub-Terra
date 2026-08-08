#include "display/engine/window.h"

class Scene {
 private:
  Window* window;

  virtual void afficher();

 protected:
  sf::Event event;

  virtual void events();

 public:
  Scene();
  virtual ~Scene() = 0;

  void Display();
};