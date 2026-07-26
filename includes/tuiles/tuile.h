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

enum Evenement {
  INONDATION,
  EMANATION,
  EBOULEMENT,
  HORREUR,
  ARRIVEE_JOUEUR,
  ACTION_JOUEUR
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
  virtual void effetTuile(enum Evenement evenement, std::array<Player*, 4> players) = 0;
  virtual bool getAcces(int direction, Player* player = nullptr);
};

class TuileDepart : Tuile {
public:
  TuileDepart(int id);
  void effetTuile(enum Evenement evenement, std::array<Player*, 4> players) override;
};

class TuileSortie : Tuile {
public:
  TuileSortie(int id);
  void effetTuile(enum Evenement evenement, std::array<Player*, 4> players) override;
};

class TuileOrdinaire : Tuile {
public:
  TuileOrdinaire(int id, std::array<bool, 4> acces);
  void effetTuile(enum Evenement evenement, std::array<Player*, 4> players) override;
};

class TuileInondable : Tuile {
private:
  bool inondee = false;
public:
  TuileInondable(int id, std::array<bool, 4> acces);
  void effetTuile(enum Evenement evenement, std::array<Player*, 4> players) override;
};

class TuileEmanation : Tuile {
private:
  bool toxique = false;
public:
  TuileEmanation(int id, std::array<bool, 4> acces);
  void effetTuile(enum Evenement evenement, std::array<Player*, 4> players) override;
};

class TuileEffondrement : Tuile {
private:
  bool effondre = false;
public:
  TuileEffondrement(int id, std::array<bool, 4> acces);
  void effetTuile(enum Evenement evenement, std::array<Player*, 4> players) override;
};

class TuileHorreur : Tuile {
public:
  TuileHorreur(int id, std::array<bool, 4> acces);
  void effetTuile(enum Evenement evenement, std::array<Player*, 4> players) override;
};

class TuileRetrecissement : Tuile {
public:
  TuileRetrecissement(int id, std::array<bool, 4> acces);
  void effetTuile(enum Evenement evenement, std::array<Player*, 4> players) override;
};

class TuileCorniche : Tuile {
private:
  bool corde = false;
public:
  TuileCorniche(int id, std::array<bool, 4> acces);
  void effetTuile(enum Evenement evenement, std::array<Player*, 4> players) override;
};

class TuileChute : Tuile {
private:
  bool corde = false;
public:
  TuileChute(int id, std::array<bool, 4> acces);
  void effetTuile(enum Evenement evenement, std::array<Player*, 4> players) override;
};

class TuileTerrainAccidente : Tuile {
public:
  TuileTerrainAccidente(int id, std::array<bool, 4> acces);
  void effetTuile(enum Evenement evenement, std::array<Player*, 4> players) override;
};
