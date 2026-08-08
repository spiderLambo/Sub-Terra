#include "../../plateau.h"
#include "display/engine/geometry.h"
#include "display/entities/player.h"
#include "tuiles/tuile.h"
#include "utils/Str_to_color.h"

class TuileDisplay : public Rectangle {
 private:
  Tuile* tuile;

 public:
  TuileDisplay(Tuile* tuile, sf::Vector2f position);
  ~TuileDisplay();
  void Display();
};

class PlateauDisplay {
 private:
  Plateau* plateau;

 public:
  PlateauDisplay(Plateau* plateau);
  ~PlateauDisplay();
  void Display(int x, int y);
};
