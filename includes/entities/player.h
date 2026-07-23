#pragma once

#include <string>

class Player {
 private:
  int pv;
  int rang;
  std::string couleur;

  bool conscient;
  bool cache;

  int actions;

 public:
  Player(int rang, std::string couleur);
  ~Player();

  //   Getters
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
  void setCache();

  //   Actions
  void resetActions();
  void ajouterActions(unsigned int nbActions);
  void utiliserActions(std::string action);
};