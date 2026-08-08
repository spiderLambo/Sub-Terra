#include "display/entities/plateau.h"
#include "display/scenes/scene.h"

class Game : public Scene {
 private:
  Plateau plateauData;
  PlateauDisplay plateau;

  void afficher() override;

 public:
  Game();
  ~Game();
};