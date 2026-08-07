#include "display/render.h"

void render() {
  // ---------- TESTS ----------
  Medecin m;
  Plongeur pl;
  Eclaireur e;
  Geologue ge;
  GardeDuCorps gdc;
  Grimpeur gr;
  std::array<Player*, 6> players = {&m, &pl, &e, &ge, &gdc, &gr};
  Plateau p(players);
  p.placerTuile(EMANATION, {false, true, false, false}, 0, 0, 0);
  p.placerTuile(SORTIE, {true, false, true, true}, 0, 1, 0);
  p.placerTuile(TERRAIN_ACCIDENTE, {true, true, false, true}, 1, 1, 0);
  p.placerTuile(DEPART, {false, false, true, true}, 5, 2, 0);
  p.placerTuile(ORDINAIRE, {true, false, false, false}, 5, 5, 0);

  Tuile* t1 = p.getTuile(1, 1);
  if (t1 != nullptr) {
    m.setTuileID(t1->getId());
    ge.setTuileID(t1->getId());
    gr.setTuileID(t1->getId());
    gdc.setTuileID(t1->getId());
    pl.setTuileID(t1->getId());
    e.setTuileID(t1->getId());
  }

  // ---------------------------------------
  PlateauDisplay pd(&p);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      if (event.type == sf::Event::GainedFocus) {
        window.setPosition(sf::Vector2i(0, 0));
      }
    }

    window.clear();

    pd.Display();

    window.display();
  }
}
