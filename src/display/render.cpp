#include "display/render.h"

void render() {
  Medecin m;
  Eclaireur e;
  Plongeur pl;
  Grimpeur gr;
  GardeDuCorps gdc;
  Ingenieur i;

  PlayerList p({&m, &e, &pl, &gr, &gdc, &i});
  Game g(p);
  g.Display();
}
