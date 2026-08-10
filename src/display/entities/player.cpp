#include "display/entities/player.h"

PlayerDisplay::PlayerDisplay(Player* player, sf::Vector2f position,
                             int tuileSize)
    : Circle(tuileSize / 6, position, Str_to_color(player->getCouleur()),
             Str_to_color("#000000"), 3.0f) {
  this->player = player;
}
PlayerDisplay::~PlayerDisplay() {}

PlayerList::PlayerList(const std::array<Player*, 6>& arr)
    : std::array<Player*, 6>(arr) {}
PlayerList::~PlayerList() {}
void PlayerList::Display(float x, float y, int tuileSize) {
  if ((*this)[1] == nullptr) {
    if ((*this)[0] != nullptr) {
      PlayerDisplay p((*this)[0],
                      sf::Vector2f(x + tuileSize / 3, y + tuileSize / 3),
                      tuileSize);
      p.Display();
    }
  } else if ((*this)[2] == nullptr) {
    if ((*this)[1] != nullptr && (*this)[0] != nullptr) {
      PlayerDisplay p1(
          (*this)[0],
          sf::Vector2f(x + tuileSize * 0.18f, y + tuileSize * 0.18f),
          tuileSize);
      PlayerDisplay p2((*this)[1],
                       sf::Vector2f(x + tuileSize / 2, y + tuileSize / 2),
                       tuileSize);
      p1.Display();
      p2.Display();
    }
  } else if ((*this)[3] == nullptr) {
    if ((*this)[2] != nullptr && (*this)[1] != nullptr &&
        (*this)[0] != nullptr) {
      PlayerDisplay p1((*this)[0],
                       sf::Vector2f(x + tuileSize / 3, y + tuileSize / 10),
                       tuileSize);
      PlayerDisplay p2((*this)[1],
                       sf::Vector2f(x + tuileSize / 10, y + tuileSize / 2),
                       tuileSize);
      PlayerDisplay p3((*this)[2],
                       sf::Vector2f(x + tuileSize * 0.58f, y + tuileSize / 2),
                       tuileSize);
      p1.Display();
      p2.Display();
      p3.Display();
    }
  } else if ((*this)[4] == nullptr) {
    if ((*this)[3] != nullptr && (*this)[2] != nullptr &&
        (*this)[1] != nullptr && (*this)[0] != nullptr) {
      PlayerDisplay p1((*this)[0],
                       sf::Vector2f(x + tuileSize / 10, y + tuileSize / 10),
                       tuileSize);
      PlayerDisplay p2((*this)[1],
                       sf::Vector2f(x + tuileSize / 10, y + tuileSize * 0.58f),
                       tuileSize);
      PlayerDisplay p3((*this)[2],
                       sf::Vector2f(x + tuileSize * 0.58f, y + tuileSize / 10),
                       tuileSize);
      PlayerDisplay p4(
          (*this)[3],
          sf::Vector2f(x + tuileSize * 0.58f, y + tuileSize * 0.58f),
          tuileSize);
      p1.Display();
      p2.Display();
      p3.Display();
      p4.Display();
    }
  } else if ((*this)[5] == nullptr) {
    if ((*this)[4] != nullptr && (*this)[3] != nullptr &&
        (*this)[2] != nullptr && (*this)[1] != nullptr &&
        (*this)[0] != nullptr) {
      PlayerDisplay p1((*this)[0],
                       sf::Vector2f(x + tuileSize / 20, y + tuileSize / 20),
                       tuileSize);
      PlayerDisplay p2((*this)[1],
                       sf::Vector2f(x + tuileSize / 20, y + tuileSize * 0.63f),
                       tuileSize);
      PlayerDisplay p3((*this)[2],
                       sf::Vector2f(x + tuileSize * 0.63f, y + tuileSize / 20),
                       tuileSize);
      PlayerDisplay p4(
          (*this)[3],
          sf::Vector2f(x + tuileSize * 0.63f, y + tuileSize * 0.63f),
          tuileSize);
      PlayerDisplay p5((*this)[4],
                       sf::Vector2f(x + tuileSize / 3, y + tuileSize / 3),
                       tuileSize);
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
      PlayerDisplay p1((*this)[0],
                       sf::Vector2f(x + tuileSize / 20, y + tuileSize / 20),
                       tuileSize);
      PlayerDisplay p2((*this)[1],
                       sf::Vector2f(x + tuileSize * 0.42f, y + tuileSize / 20),
                       tuileSize);
      PlayerDisplay p3((*this)[2],
                       sf::Vector2f(x + tuileSize / 5, y + tuileSize * 0.35f),
                       tuileSize);
      PlayerDisplay p4(
          (*this)[3],
          sf::Vector2f(x + tuileSize * 0.63f, y + tuileSize * 0.35f),
          tuileSize);
      PlayerDisplay p5((*this)[4],
                       sf::Vector2f(x + tuileSize / 20, y + tuileSize * 0.63f),
                       tuileSize);
      PlayerDisplay p6(
          (*this)[5],
          sf::Vector2f(x + tuileSize * 0.42f, y + tuileSize * 0.63f),
          tuileSize);
      p3.Display();
      p1.Display();
      p2.Display();
      p4.Display();
      p5.Display();
      p6.Display();
    }
  }
}