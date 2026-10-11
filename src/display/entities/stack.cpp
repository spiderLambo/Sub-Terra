#include "display/entities/stack.h"

Stack::Stack(sf::Vector2f taille, sf::Vector2f pos, GameStack* stack)
    : Rectangle(taille, pos, sf::Color::Black, sf::Color::White, 1.0f),
      stack(stack),
      reste("", pos) {
  reste.setString(std::to_string(stack->size()));

  const sf::FloatRect bounds = reste.getLocalBounds();

  reste.setOrigin(bounds.left + bounds.width / 2.f,
                  bounds.top + bounds.height / 2.f);

  reste.setPosition(pos.x + taille.x / 2.f, pos.y + taille.y / 2.f);
}

Stack::~Stack() { delete stack; }

void Stack::Display() {
  Rectangle::Display();
  reste.Display();
}