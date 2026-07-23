#include "main.h"

int main() {
  Plongeur p;
  std::cout << "Plongeur" << std::endl;
  std::cout << p.estCache() << std::endl;
  p.setCache();
  std::cout << p.estCache() << std::endl;

  Eclaireur e;
  std::cout << "Eclaireur" << std::endl;
  std::cout << e.estCache() << std::endl;
  e.setCache();
  std::cout << e.estCache() << std::endl;

  return 0;
}