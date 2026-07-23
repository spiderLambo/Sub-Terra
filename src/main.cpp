#include "main.h"

int main() {
  Player p(1, "#FFFFFF");
  std::cout << "Pv : " << p.getPv() << std::endl;
  p.subirDegats(1);
  std::cout << "Pv : " << p.getPv() << std::endl;
  p.recupererPv();
  std::cout << "Pv : " << p.getPv() << std::endl;
  p.recupererPv();
  std::cout << "Pv : " << p.getPv() << std::endl;
  std::cout << "Conscient : " << p.estConscient() << std::endl;
  p.setConscient();
  std::cout << "Conscient : " << p.estConscient() << std::endl;
  p.setConscient();
  std::cout << "Conscient : " << p.estConscient() << std::endl;
  std::cout << "Cache : " << p.estCache() << std::endl;
  p.setCache();
  std::cout << "Cache : " << p.estCache() << std::endl;
  p.setCache();
  std::cout << "Cache : " << p.estCache() << std::endl;

  return 0;
}