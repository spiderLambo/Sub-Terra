#pragma once

#include "tuiles/tuile.h"
#include <array>
#include <vector>

class Plateau {
private:
  std::array<std::array<Tuile*, 128>, 128> plateau;
  std::vector<Tuile*> tuilesHorreur;
  std::vector<Tuile*> tuilesInondation;
  std::vector<Tuile*> tuilesEmanation;
  std::vector<Tuile*> tuilesEffondrement;

public:
  Plateau();
  ~Plateau();

  Tuile* getTuile(int x, int y);
  std::vector<Tuile*> getTuilesHorreur();
  std::vector<Tuile*> getTuilesInondation();
  std::vector<Tuile*> getTuilesEmanation();
  std::vector<Tuile*> getTuilesEffondrement();
  std::pair<int, int> getCoordonnees(int tuileId);

  void placerTuile(enum TuileType type, std::array<bool, 4> acces, int x, int y, int dir, std::pair<int, int> nbEboulement = std::make_pair(-1, -1));
  bool mouvementValide(int x, int y, int direction, bool deplacement = true, Player* player = nullptr);

  void affichePlateau();
};
