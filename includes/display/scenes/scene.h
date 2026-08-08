#include "display/engine/window.h"

class Scene {
 private:
  Window* window;

  virtual void afficher();

 public:
  Scene();
  virtual ~Scene() = 0;

  void Display();
};