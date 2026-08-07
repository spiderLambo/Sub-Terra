#include "display/engine/geometry.h"
#include "tuiles/tuile.h"
#include "utils/Str_to_color.h"

class TuileDisplay : public Rectangle {
 private:
  Tuile* tuile;

 public:
  TuileDisplay(Tuile* tuile);
  ~TuileDisplay();
};
