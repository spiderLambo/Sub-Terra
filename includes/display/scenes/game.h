#include "display/entities/plateau.h"
#include "display/scenes/scene.h"

class Game : public Scene {
 private:
  Plateau plateauData;
  PlateauDisplay plateau;

  void afficher() override;
  void events() override;

 public:
  Game();
  ~Game();
};