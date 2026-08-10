#include "display/engine/window.h"

class Image : public sf::Sprite {
 private:
  Window* window;
  sf::Texture texture;

 public:
  Image(std::string path, int width, std::pair<int, int> coordones = {0, 0});
  ~Image();
  void Display();
};