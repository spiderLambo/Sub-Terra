#include "display/render.h"

void render() {
  std::array<Player*, 6> players = {nullptr};
  Plateau p(players);
  p.placerTuile(EMANATION, {true, true, true, true}, 0, 0, 1);
  p.placerTuile(SORTIE, {true, true, true, true}, 0, 1, 3);
  p.placerTuile(TERRAIN_ACCIDENTE, {true, true, true, true}, 1, 1, 3);
  p.placerTuile(HORREUR, {true, true, true, true}, 1, 2, 3);

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
