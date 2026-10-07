#include "entities/stack.h"

GameStack::GameStack() {
  static std::random_device seed;
  static std::mt19937 generator(seed());
  static std::uniform_int_distribution<unsigned int> d1(0, 4);

  tableau t = buildTableau();

  unsigned int endPos = d1(generator);

  if (endPos == 0) push(new TuileSortie(65));

  while (t.n > 0) {
    std::uniform_int_distribution<unsigned int> d2(0, t.n - 1);
    unsigned int i = d2(generator);
    unsigned int fin = t.n - 1;
    Tuile* aux = t.tuile[i];
    t.tuile[i] = t.tuile[fin];
    push(aux);
    --t.n;
    if (endPos > 0) {
      --endPos;
      if (endPos == 0) push(new TuileSortie(65));
    }
  }
}
GameStack::~GameStack() {
  while (!empty()) {
    delete top();
    pop();
  }
}

tableau GameStack::buildTableau() {
  tableau t;
  t.n = 64;

  // Ordinaires
  for (int i = 0; i < 3; ++i)
    t.tuile[i] = new TuileOrdinaire(i, {true, true, true, true});
  for (int i = 3; i < 6; ++i)
    t.tuile[i] = new TuileOrdinaire(i, {false, true, true, true});
  for (int i = 6; i < 8; ++i)
    t.tuile[i] = new TuileOrdinaire(i, {false, false, false, true});
  for (int i = 8; i < 12; ++i)
    t.tuile[i] = new TuileOrdinaire(i, {false, true, false, true});
  for (int i = 12; i < 16; ++i)
    t.tuile[i] = new TuileOrdinaire(i, {false, false, true, true});

  // Inondables
  for (int i = 16; i < 18; ++i)
    t.tuile[i] = new TuileInondable(i, {false, true, true, true});
  for (int i = 18; i < 20; ++i)
    t.tuile[i] = new TuileInondable(i, {true, true, true, true});
  for (int i = 20; i < 24; ++i)
    t.tuile[i] = new TuileInondable(i, {false, true, false, true});

  // Gaz
  for (int i = 24; i < 26; ++i)
    t.tuile[i] = new TuileEmanation(i, {false, true, true, true});
  for (int i = 26; i < 32; ++i)
    t.tuile[i] = new TuileEmanation(i, {false, false, true, true});

  // Eboulement
  t.tuile[32] = new TuileEffondrement(32, {false, false, true, true}, {3, 6});
  t.tuile[33] = new TuileEffondrement(33, {false, false, true, true}, {2, 4});
  t.tuile[34] = new TuileEffondrement(34, {false, false, true, true}, {2, 6});
  t.tuile[35] = new TuileEffondrement(35, {false, false, true, true}, {1, 5});

  t.tuile[36] = new TuileEffondrement(36, {false, true, true, true}, {4, 6});
  t.tuile[37] = new TuileEffondrement(37, {false, true, true, true}, {1, 6});
  t.tuile[38] = new TuileEffondrement(38, {false, true, true, true}, {1, 4});
  t.tuile[39] = new TuileEffondrement(39, {false, true, true, true}, {1, 3});
  t.tuile[40] = new TuileEffondrement(40, {false, true, true, true}, {2, 3});
  t.tuile[41] = new TuileEffondrement(41, {false, true, true, true}, {4, 5});
  t.tuile[42] = new TuileEffondrement(42, {false, true, true, true}, {2, 5});
  t.tuile[43] = new TuileEffondrement(43, {false, true, true, true}, {3, 5});

  // Horreur
  for (int i = 44; i < 46; ++i)
    t.tuile[i] = new TuileHorreur(i, {false, false, true, true});
  for (int i = 46; i < 52; ++i)
    t.tuile[i] = new TuileHorreur(i, {false, false, false, true});

  // Retrecicement
  for (int i = 52; i < 55; ++i) t.tuile[i] = new TuileRetrecissement(i);

  // Corniche
  for (int i = 55; i < 58; ++i) t.tuile[i] = new TuileCorde(i, 3, CORNICHE);

  // Chute
  for (int i = 58; i < 61; ++i) t.tuile[i] = new TuileCorde(i, 1, CHUTE);

  // Terain acidente
  for (int i = 61; i < 64; ++i) t.tuile[i] = new TuileTerrainAccidente(i);

  return t;
}

void GameStack::DebugDisplay() {
  std::stack<Tuile*> s;
  while (!empty()) {
    std::cout << top()->getId() << std::endl;
    s.push(top());
    pop();
  }
  while (!s.empty()) {
    push(s.top());
    s.pop();
  }
}