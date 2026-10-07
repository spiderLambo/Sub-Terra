#include <iostream>
#include <random>
#include <stack>

#include "entities/tuile.h"

struct tableau {
  Tuile* tuile[64];
  unsigned int n;
};

class GameStack : public std::stack<Tuile*> {
 private:
  tableau buildTableau();

 public:
  GameStack();
  ~GameStack();
  void DebugDisplay();
};