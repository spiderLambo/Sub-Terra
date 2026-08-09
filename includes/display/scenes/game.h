#include "display/entities/plateau.h"
#include "display/scenes/scene.h"

class Game : public Scene {
 private:
  Plateau plateauData;
  PlateauDisplay plateau;

  std::pair<int, int> coordonesPlateau;

  void VuePlateau();

  void afficher() override;
  void events() override;

  void dessinerContours();

 public:
  Game();
  ~Game();
};