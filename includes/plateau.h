#pragma once

#include "tuiles/tuile.h"
#include <array>
#include <vector>

class Plateau {
private:
  const int DIM = 128;
  const int MID = 64;

  std::array<std::array<Tuile*, DIM>, DIM> plateau;
  std::array<Player*, 6> players;
  std::vector<Tuile*> tuilesHorreur;
  std::vector<Tuile*> tuilesInondation;
  std::vector<Tuile*> tuilesEmanation;
  std::vector<Tuile*> tuilesEffondrement;

public:
  Plateau(std::array<Player*, 6> players);
  ~Plateau();

  Tuile* getTuile(int x, int y);
  std::vector<Tuile*> getTuilesHorreur();
  std::vector<Tuile*> getTuilesInondation();
  std::vector<Tuile*> getTuilesEmanation();
  std::vector<Tuile*> getTuilesEffondrement();
  std::pair<int, int> getCoordonnees(int tuileId);
  std::array<Player*, 6> getPlayersOnTuile(Tuile* tuile);

  void placerTuile(enum TuileType type, std::array<bool, 4> acces, int x, int y, int dir, std::pair<int, int> nbEboulement = std::make_pair(-1, -1));
  bool mouvementValide(int x, int y, int direction, bool deplacement = true, Player* player = nullptr);

  void Horreur();
  void Inondation();
  void Emanation();
  void Effondrement();

  std::pair<std::pair<int, int>, std::pair<int, int>> getDimensions(); // rends coordonnees des coins haut gauche et bas droit
  void affichePlateau();
};
