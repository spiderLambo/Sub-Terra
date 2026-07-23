#include "main.h"

int main() {
  Plongeur p;
  std::cout << "Plongeur" << std::endl;
  std::cout << p.getCouleur() << std::endl;

  Eclaireur e;
  std::cout << "Eclaireur" << std::endl;
  std::cout << e.getCouleur() << std::endl;

  Geologue g;
  std::cout << "Geologuqe" << std::endl;
  std::cout << g.getCouleur() << std::endl;

  Ingenieur i;
  std::cout << "Ingenieur" << std::endl;
  std::cout << i.getCouleur() << std::endl;

  Grimpeur gr;
  std::cout << "Grimpeur" << std::endl;
  std::cout << gr.getCouleur() << std::endl;

  Medecin m;
  std::cout << "Medecin" << std::endl;
  std::cout << m.getCouleur() << std::endl;

  return 0;
}