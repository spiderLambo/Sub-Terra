#pragma once
#include "display/engine/geometry.h"
#include "display/engine/text.h"
#include "entities/stack.h"

class Stack : public Rectangle {
 private:
  GameStack* stack;
  Texte reste;

 public:
  Stack(sf::Vector2f taille, sf::Vector2f pos, GameStack* stack);
  ~Stack();
  void Display();
};