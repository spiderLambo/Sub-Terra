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
  std::cout << gr.getPv() << std::endl;
  gr.subirDegats(20);
  std::cout << gr.getPv() << std::endl;
  gr.recupererPv();
  gr.recupererPv();
  std::cout << gr.getPv() << std::endl;
  gr.recupererPv();
  std::cout << gr.getPv() << std::endl;
  gr.recupererPv();
  std::cout << gr.getPv() << std::endl;

  Medecin m;
  std::cout << "Medecin" << std::endl;
  std::cout << m.getCouleur() << std::endl;

  GardeDuCorp gdc;
  std::cout << "Garde du corp" << std::endl;
  std::cout << gdc.getPv() << std::endl;
  gdc.subirDegats(20);
  std::cout << gdc.getPv() << std::endl;
  gdc.recupererPv();
  gdc.recupererPv();
  gdc.recupererPv();
  gdc.recupererPv();
  std::cout << gdc.getPv() << std::endl;
  gdc.recupererPv();
  std::cout << gdc.getPv() << std::endl;
  gdc.recupererPv();
  std::cout << gdc.getPv() << std::endl;

  Chef c;
  std::cout << "Chef" << std::endl;
  std::cout << c.getCouleur() << std::endl;

  return 0;
}