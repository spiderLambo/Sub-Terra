#include "display/entities/player.h"

PlayerDisplay::PlayerDisplay(Player* player, sf::Vector2f position)
    : Circle(16.0f, position, Str_to_color(player->getCouleur()),
             Str_to_color("#000000"), 5.0f) {
  this->player = player;
}
PlayerDisplay::~PlayerDisplay() { delete player; }