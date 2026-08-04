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
  int id;
  enum TuileType type;
  std::array<bool, 4> acces;
  std::string couleur = "#FFFFFF";

public:
  Tuile(int id, enum TuileType type, std::array<bool, 4> acces, std::string couleur);
  virtual ~Tuile() = default;

  int getId();

  void rotation();
  virtual void effetTuile(std::array<Player*, 6> players, int nbEboulement = -1);
  virtual void effetArriveeJoueur(Player* player);
  virtual void effetSortieJoueur(Player* player);
  virtual void effetActionJoueur(Player* player);
  virtual bool getAcces(int direction, Player* player = nullptr);
};

class TuileDepart : public Tuile {
public:
  TuileDepart(int id);
};

class TuileSortie : public Tuile {
public:
  TuileSortie(int id);
};

class TuileOrdinaire : public Tuile {
public:
  TuileOrdinaire(int id, std::array<bool, 4> acces);
};

class TuileInondable : public Tuile {
private:
  bool inondee = false;
public:
  TuileInondable(int id, std::array<bool, 4> acces);
  void effetTuile(std::array<Player*, 6> players, int nbEboulement = -1) override;
};

class TuileEmanation : public Tuile {
private:
  bool toxique = false;
  bool gardeDuCorps = false;
public:
  TuileEmanation(int id, std::array<bool, 4> acces);
  void effetTuile(std::array<Player*, 6> players, int nbEboulement = -1) override;
  void effetArriveeJoueur(Player* player) override;
  void effetSortieJoueur(Player* player) override;
};

class TuileEffondrement : public Tuile {
private:
  bool effondre = false;
  std::pair<int, int> numEboulement;
public:
  TuileEffondrement(int id, std::array<bool, 4> acces, std::pair<int, int> numEboulement);
  void effetTuile(std::array<Player*, 6> players, int nbEboulement = -1) override;
  void effetActionJoueur(Player* player) override;
  bool getAcces(int direction, Player* player = nullptr) override;
};

class TuileHorreur : public Tuile {
public:
  TuileHorreur(int id, std::array<bool, 4> acces);
  void effetTuile(std::array<Player*, 6> players, int nbEboulement = -1) override;
};

class TuileRetrecissement : public Tuile {
public:
  TuileRetrecissement(int id, std::array<bool, 4> acces);
};

class TuileCorde : public Tuile {
private:
  bool corde = false;
  int cordeDir;
public:
  TuileCorde(int id, int cordeDir, enum TuileType type);
  void effetActionJoueur(Player* player) override;
  bool getAcces(int direction, Player* player = nullptr) override;
};

class TuileTerrainAccidente : public Tuile {
public:
  TuileTerrainAccidente(int id, std::array<bool, 4> acces);
  void effetArriveeJoueur(Player* player) override;
};
