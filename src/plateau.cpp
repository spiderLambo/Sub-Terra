#include "plateau.h"

Plateau::Plateau(std::array<Player*, 6> players) {
  this->players = players;
  for (int i = 0; i < DIM; i++) {
    for (int j = 0; j < DIM; j++) {
      plateau[i][j] = nullptr;
    }
  }
  placerTuile(DEPART, {true, true, true, true}, MID, MID, 0);
}

Plateau::~Plateau() {
  for (int i = 0; i < DIM; i++) {
    for (int j = 0; j < DIM; j++) {
      if (plateau[i][j] != nullptr) delete plateau[i][j];
    }
  }
}

Tuile* Plateau::getTuile(int x, int y) { return plateau[y][x]; }

std::vector<Tuile*> Plateau::getTuilesHorreur() { return tuilesHorreur; }

std::vector<Tuile*> Plateau::getTuilesInondation() { return tuilesInondation; }

std::vector<Tuile*> Plateau::getTuilesEmanation() { return tuilesEmanation; }

std::vector<Tuile*> Plateau::getTuilesEffondrement() {
  return tuilesEffondrement;
}

std::pair<int, int> Plateau::getCoordonnees(int tuileId) {
  return std::make_pair(tuileId % DIM, tuileId / DIM);
}

std::array<Player*, 6> Plateau::getPlayersOnTuile(Tuile* tuile) {
  std::array<Player*, 6> playersOnTuile;
  for (int i = 0; i < 6; i++) playersOnTuile[i] = nullptr;
  if (tuile == nullptr) return playersOnTuile;
  int nbPlayers = 0;
  for (int i = 0; i < 6; i++) {
    if (players[i] != nullptr && players[i]->getTuileID() == tuile->getId()) {
      playersOnTuile[nbPlayers++] = players[i];
    }
  }
  return playersOnTuile;
}

void Plateau::placerTuile(enum TuileType type, std::array<bool, 4> acces, int x,
                          int y, int dir, std::pair<int, int> nbEboulement) {
  Tuile* tuile;
  int id = x + DIM * y;
  switch (type) {
    case DEPART:
      tuile = new TuileDepart(id);
      break;
    case SORTIE:
      tuile = new TuileSortie(id);
      break;
    case ORDINAIRE:
      tuile = new TuileOrdinaire(id, acces);
      break;
    case INONDABLE:
      tuile = new TuileInondable(id, acces);
      tuilesInondation.push_back(tuile);
      break;
    case EMANATION:
      tuile = new TuileEmanation(id, acces);
      tuilesEmanation.push_back(tuile);
      break;
    case EFFONDREMENT:
      tuile = new TuileEffondrement(id, acces, nbEboulement);
      tuilesEffondrement.push_back(tuile);
      break;
    case HORREUR:
      tuile = new TuileHorreur(id, acces);
      tuilesHorreur.push_back(tuile);
      break;
    case RETRECISSEMENT:
      tuile = new TuileRetrecissement(id, acces);
      break;
    case CORNICHE:
      tuile = new TuileCorde(id, dir, CORNICHE);
      break;
    case CHUTE:
      tuile = new TuileCorde(id, (dir + 2) % 4, CHUTE);
      break;
    case TERRAIN_ACCIDENTE:
      tuile = new TuileTerrainAccidente(id, acces);
      break;
    default:
      return;
  }
  while (!tuile->getAcces((dir + 2) % 4, nullptr)) tuile->rotation();
  plateau[y][x] = tuile;
}

bool Plateau::mouvementValide(int x, int y, int direction, bool deplacement,
                              Player* player) {
  int xDest = x;
  int yDest = y;
  switch (direction) {
    case 0:
      yDest++;
      break;
    case 1:
      xDest--;
      break;
    case 2:
      yDest--;
      break;
    case 3:
      xDest++;
      break;
    default:
      return false;
  }

  Tuile* tuileOrigine = getTuile(x, y);
  if (tuileOrigine == nullptr) return false;
  Tuile* tuileDest = getTuile(xDest, yDest);
  if (tuileDest == nullptr) {
    if (!deplacement) {
      return tuileOrigine->getAcces(direction, player);
    }
    return false;
  }

  return tuileOrigine->getAcces(direction, player) &&
         tuileDest->getAcces((direction + 2) % 4, player);
}

void Plateau::Horreur() {
  Tuile* selection = nullptr;
  // TODO: choisir tuile horreur la plus proche du joueur

  if (selection != nullptr) {
    std::array<Player*, 6> playersOnTuile = getPlayersOnTuile(selection);
    selection->effetTuile(playersOnTuile);
  }
}

void Plateau::Inondation() {
  for (unsigned int i = 0; i < tuilesInondation.size(); i++) {
    if (tuilesInondation[i] != nullptr) {
      std::array<Player*, 6> playersOnTuile =
          getPlayersOnTuile(tuilesInondation[i]);
      tuilesInondation[i]->effetTuile(playersOnTuile);
    }
  }
}

void Plateau::Emanation() {
  for (unsigned int i = 0; i < tuilesEmanation.size(); i++) {
    if (tuilesEmanation[i] != nullptr) {
      std::array<Player*, 6> playersOnTuile =
          getPlayersOnTuile(tuilesEmanation[i]);
      tuilesEmanation[i]->effetTuile(playersOnTuile);
    }
  }
}

void Plateau::Effondrement() {
  // TODO: selection aléatoire
  int nbEboulement = 1;
  for (unsigned int i = 0; i < tuilesEffondrement.size(); i++) {
    if (tuilesEffondrement[i] != nullptr) {
      std::array<Player*, 6> playersOnTuile =
          getPlayersOnTuile(tuilesEffondrement[i]);
      tuilesEffondrement[i]->effetTuile(playersOnTuile, nbEboulement);
    }
  }
}

<<<<<<< HEAD
std::pair<std::pair<int, int>, std::pair<int, int>> Plateau::getDimensions() {
  int minX = MID, maxX = MID, minY = MID, maxY = MID;
  for (int x = 0; x < DIM; x++) {
    for (int y = 0; y < DIM; y++) {
      if (plateau[y][x] != nullptr) {
        if (x < minX) minX = x;
        else if (x > maxX) maxX = x;
        if (y < minY) minY = y;
        else if (y > maxY) maxY = y;
      }
    }
  }
  return std::make_pair(std::make_pair(minX, minY), std::make_pair(maxX, maxY));
}

>>>>>>> c74bf704120b6693a9b7f69080a46f696973b078
