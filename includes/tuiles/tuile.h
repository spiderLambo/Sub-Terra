#pragma once
#include "entities/player.h"
#include <array>
#include <string>

enum TuileType {
  DEPART,
  SORTIE,
  ORDINAIRE,
  INONDABLE,
  EMANATION,
  EFFONDREMENT,
  HORREUR,
  RETRECISSEMENT,
  CORNICHE,
  CHUTE,
  TERRAIN_ACCIDENTE
};

class Tuile {
protected:
  unsigned int id;
  enum TuileType type;
  std::array<bool, 4> acces;
  std::string couleur = "#FFFFFF";

public:
  Tuile(int id, enum TuileType type, std::array<bool, 4> acces, std::string couleur);

  void rotation();
  virtual void effetTuile(std::array<Player*, 6> players);
  virtual void effetArriveeJoueur(Player* player);
  virtual void effetSortieJoueur(Player* player);
  virtual void effetActionJoueur(Player* player);
  virtual bool getAcces(int direction, Player* player = nullptr);
};

class TuileDepart : Tuile {
public:
  TuileDepart(int id);
};

class TuileSortie : Tuile {
public:
  TuileSortie(int id);
};

class TuileOrdinaire : Tuile {
public:
  TuileOrdinaire(int id, std::array<bool, 4> acces);
};

class TuileInondable : Tuile {
private:
  bool inondee = false;
public:
  TuileInondable(int id, std::array<bool, 4> acces);
  void effetTuile(std::array<Player*, 6> players) override;
};

class TuileEmanation : Tuile {
private:
  bool toxique = false;
  bool gardeDuCorps = false;
public:
  TuileEmanation(int id, std::array<bool, 4> acces);
  void effetTuile(std::array<Player*, 6> players) override;
  void effetArriveeJoueur(Player* player) override;
  void effetSortieJoueur(Player* player) override;
};

class TuileEffondrement : Tuile {
private:
  bool effondre = false;
  std::pair<int, int> numEboulement;
public:
  TuileEffondrement(int id, std::array<bool, 4> acces, std::pair<int, int> numEboulement);
  void effetTuile(std::array<Player*, 6> players) override;
  void effetActionJoueur(Player* player) override;
  bool getAcces(int direction, Player* player = nullptr) override;
};

class TuileHorreur : Tuile {
public:
  TuileHorreur(int id, std::array<bool, 4> acces);
  void effetTuile(std::array<Player*, 6> players) override;
};

class TuileRetrecissement : Tuile {
public:
  TuileRetrecissement(int id, std::array<bool, 4> acces);
};

class TuileCorde : Tuile {
private:
  bool corde = false;
  int cordeDir;
public:
  TuileCorde(int id, std::array<bool, 4> acces, int cordeDir, enum TuileType type);
  void effetActionJoueur(Player* player) override;
  bool getAcces(int direction, Player* player = nullptr) override;
};

class TuileTerrainAccidente : Tuile {
public:
  TuileTerrainAccidente(int id, std::array<bool, 4> acces);
  void effetArriveeJoueur(Player* player) override;
};
