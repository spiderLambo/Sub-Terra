#include "display/engine/texture.h"

Image::Image(const std::string path, int width, std::pair<int, int> coordones) {
  if (texture.loadFromFile(path)) {
    this->setTexture(texture);
    window = &::window;
  }

  this->setPosition(static_cast<float>(coordones.first),
                    static_cast<float>(coordones.second));

  float currentWidth = this->getLocalBounds().width;
  if (currentWidth > 0.0f) {
    float factor = width / currentWidth;
    this->setScale(factor, factor);
  }
}
Image::~Image() {}

void Image::Display() { (*window).draw(*this); }