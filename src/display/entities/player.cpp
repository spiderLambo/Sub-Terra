#include "display/entities/player.h"

PlayerDisplay::PlayerDisplay(Player* player, sf::Vector2f position)
    : Circle(16.0f, position, Str_to_color(player->getCouleur()),
             Str_to_color("#000000"), 3.0f) {
  this->player = player;
}
PlayerDisplay::~PlayerDisplay() {}

PlayerList::PlayerList(const std::array<Player*, 6>& arr)
    : std::array<Player*, 6>(arr) {}
PlayerList::~PlayerList() {}
void PlayerList::Display(float x, float y) {
  if ((*this)[1] == nullptr) {
    if ((*this)[0] != nullptr) {
      PlayerDisplay p((*this)[0], sf::Vector2f(x + 34.0f, y + 34.0f));
      p.Display();
    }
  } else if ((*this)[2] == nullptr) {
    if ((*this)[1] != nullptr && (*this)[0] != nullptr) {
      PlayerDisplay p1((*this)[0], sf::Vector2f(x + 18.0f, y + 18.0f));
      PlayerDisplay p2((*this)[1], sf::Vector2f(x + 50.0f, y + 50.0f));
      p1.Display();
      p2.Display();
    }
  } else if ((*this)[3] == nullptr) {
    if ((*this)[2] != nullptr && (*this)[1] != nullptr &&
        (*this)[0] != nullptr) {
      PlayerDisplay p1((*this)[0], sf::Vector2f(x + 34.0f, y + 10.0f));
      PlayerDisplay p2((*this)[1], sf::Vector2f(x + 10.0f, y + 50.0f));
      PlayerDisplay p3((*this)[2], sf::Vector2f(x + 58.0f, y + 50.0f));
      p1.Display();
      p2.Display();
      p3.Display();
    }
  } else if ((*this)[4] == nullptr) {
    if ((*this)[3] != nullptr && (*this)[2] != nullptr &&
        (*this)[1] != nullptr && (*this)[0] != nullptr) {
      PlayerDisplay p1((*this)[0], sf::Vector2f(x + 10.0f, y + 10.0f));
      PlayerDisplay p2((*this)[1], sf::Vector2f(x + 10.0f, y + 58.0f));
      PlayerDisplay p3((*this)[2], sf::Vector2f(x + 58.0f, y + 10.0f));
      PlayerDisplay p4((*this)[3], sf::Vector2f(x + 58.0f, y + 58.0f));
      p1.Display();
      p2.Display();
      p3.Display();
      p4.Display();
    }
  } else if ((*this)[5] == nullptr) {
    if ((*this)[4] != nullptr && (*this)[3] != nullptr &&
        (*this)[2] != nullptr && (*this)[1] != nullptr &&
        (*this)[0] != nullptr) {
      PlayerDisplay p1((*this)[0], sf::Vector2f(x + 5.0f, y + 5.0f));
      PlayerDisplay p2((*this)[1], sf::Vector2f(x + 5.0f, y + 63.0f));
      PlayerDisplay p3((*this)[2], sf::Vector2f(x + 63.0f, y + 5.0f));
      PlayerDisplay p4((*this)[3], sf::Vector2f(x + 63.0f, y + 63.0f));
      PlayerDisplay p5((*this)[4], sf::Vector2f(x + 34.0f, y + 34.0f));
      p1.Display();
      p2.Display();
      p3.Display();
      p4.Display();
      p5.Display();
    }
  } else {
    if ((*this)[5] != nullptr && (*this)[4] != nullptr &&
        (*this)[3] != nullptr && (*this)[2] != nullptr &&
        (*this)[1] != nullptr && (*this)[0] != nullptr) {
      PlayerDisplay p1((*this)[0], sf::Vector2f(x + 5.0f, y + 5.0f));
      PlayerDisplay p2((*this)[1], sf::Vector2f(x + 42.0f, y + 5.0f));
      PlayerDisplay p3((*this)[2], sf::Vector2f(x + 20.0f, y + 35.0f));
      PlayerDisplay p4((*this)[3], sf::Vector2f(x + 63.0f, y + 35.0f));
      PlayerDisplay p5((*this)[4], sf::Vector2f(x + 5.0f, y + 63.0f));
      PlayerDisplay p6((*this)[5], sf::Vector2f(x + 42.0f, y + 63.0f));
      p3.Display();
      p1.Display();
      p2.Display();
      p4.Display();
      p5.Display();
      p6.Display();
    }
  }
}