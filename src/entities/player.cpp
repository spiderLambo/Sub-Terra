#include "entities/player.h"

Player::Player(int rang, std::string couleur) : rang(rang), couleur(couleur) {
  this->pv = 3;
  this->conscient = true;
  this->cache = false;
  this->actions = 3;
}

Player::~Player() {}

// Getters
int Player::getPv() const { return this->pv; }
int Player::getRang() const { return this->rang; }
std::string Player::getCouleur() const { return this->couleur; }
bool Player::estCache() const { return this->cache; }
bool Player::estConscient() const { return this->conscient; }
int Player::getActions() const { return this->actions; }