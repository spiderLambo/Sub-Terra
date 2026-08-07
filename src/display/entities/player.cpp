#include "display/entities/player.h"

PlayerDisplay::PlayerDisplay(Player* player)
    : Circle(10.0f, sf::Vector2f(50.0f, 50.0f),
             Str_to_color(player->getCouleur()), Str_to_color("#000000"),
             2.0f) {
  this->player = player;
}
PlayerDisplay::~PlayerDisplay() { delete player; }
