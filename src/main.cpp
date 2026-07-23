#include "main.h"

int main() {
  Player p(1, "#FFFFFF");
  std::cout << "Pv : " << p.getPv() << std::endl
            << "Rang : " << p.getRang() << std::endl
            << "Couleur : " << p.getCouleur() << std::endl
            << "Cache : " << p.estCache() << std::endl
            << "Conscient : " << p.estConscient() << std::endl
            << "Actions : " << p.getActions() << std::endl;
  return 0;
}