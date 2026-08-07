#pragma once
#include "display/engine/geometry.h"
#include "entities/player.h"
#include "utils/Str_to_color.h"

class PlayerDisplay : public Circle {
 private:
  Player* player;

 public:
  PlayerDisplay(Player* player, sf::Vector2f position);
  ~PlayerDisplay();
};