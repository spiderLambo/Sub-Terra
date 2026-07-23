#pragma once

#include <string>

class Player {
 protected:
  static const int maxPv = 3;
  int pv;
  int rang;
  std::string couleur;

  bool conscient;
  bool cache;
  int actions;

 public:
  Player(int rang, std::string couleur);
  virtual ~Player() = 0;

  // Getters
  int getPv() const;
  int getRang() const;
  std::string getCouleur() const;
  bool estConscient() const;
  bool estCache() const;
  int getActions() const;

  // Gestion de l'etat
  void subirDegats(unsigned int degats);
  void recupererPv();
  void setConscient();
  virtual void setCache();

  //   Actions
  void resetActions();
  void ajouterActions(unsigned int nbActions);
  void utiliserActions(std::string action);
};

// ------------- Roles -------------
class Plongeur : public Player {
 public:
  Plongeur();
  ~Plongeur();
};
class Eclaireur : public Player {
 public:
  Eclaireur();
  ~Eclaireur();

  void setCache() override;
};