#include "display/render.h"

void render() {
  // ---------- TESTS ----------
  std::array<Player*, 6> players = {nullptr};
  Plateau p(players);
  p.placerTuile(EMANATION, {true, true, true, true}, 66, 66, 0);

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
