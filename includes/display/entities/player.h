#pragma once
#include <array>

#include "display/engine/geometry.h"
#include "entities/player.h"
#include "utils/Str_to_color.h"

class PlayerDisplay : public Circle {
 private:
  Player* player;

 public:
  PlayerDisplay(Player* player, sf::Vector2f position, int tuileSize);
  ~PlayerDisplay();
};

class PlayerList : public std::array<Player*, 6> {
 public:
  using std::array<Player*, 6>::array;

  PlayerList(const std::array<Player*, 6>& arr);
  ~PlayerList();

  void Display(float x, float y, int tuileSize);
};