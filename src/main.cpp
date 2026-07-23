#include "main.h"

int main() {
  Player p(1, "#FFFFFF");
  std::cout << "Actions : " << p.getActions() << std::endl;
  p.ajouterActions(3);
  std::cout << "Actions : " << p.getActions() << std::endl;
  p.resetActions();
  std::cout << "Actions : " << p.getActions() << std::endl;

  return 0;
}