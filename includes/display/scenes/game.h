#include <algorithm>

#include "display/engine/texture.h"
#include "display/entities/plateau.h"
#include "display/scenes/scene.h"

class Game : public Scene {
 private:
  PlayerList players;
  Plateau plateauData;
  PlateauDisplay plateau;

  std::pair<int, int> coordonesPlateau;

  bool click;
  std::pair<int, int> coordonnesClick;
  int tuileSize;

  void VuePlateau();

  void afficher() override;
  void events() override;

  void dessinerContours();

 public:
  Game(PlayerList players = {});
  ~Game();
};