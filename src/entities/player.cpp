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

// Gestion de l'etat
void Player::subirDegats(unsigned int degats) { this->pv -= degats; }
void Player::recupererPv() {
  if (this->pv < maxPv) {
    ++this->pv;
  }
}
void Player::setConscient() { this->conscient = !this->conscient; }
void Player::setCache() { this->cache = !this->cache; }