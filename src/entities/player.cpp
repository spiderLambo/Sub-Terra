#include "entities/player.h"

Player::Player(int rang, std::string couleur) : rang(rang), couleur(couleur) {
  this->pv = 3;
  this->conscient = true;
  this->cache = false;
  this->actions = 2;
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

void Player::subirDegats(unsigned int degats) {
  if (degats <= maxPv()) {
    this->pv -= degats;
  } else
    this->pv = 0;

  if (this->pv == 0) this->conscient = false;
}
void Player::recupererPv() {
  if (this->pv < maxPv()) {
    ++this->pv;
  }
}
void Player::setConscient() { this->conscient = !this->conscient; }
void Player::setCache() { this->cache = !this->cache; }

//   Actions

void Player::resetActions() { this->actions = 2; }
void Player::ajouterActions(unsigned int nbAction) {
  this->actions += nbAction;
}
// TODO: Implementer utiliserActions

// ------------- Roles -------------

// Plongeur
Plongeur::Plongeur() : Player(1, "#FFFF00") {}
Plongeur::~Plongeur() {}

// Eclaireur
Eclaireur::Eclaireur() : Player(2, "#000000") { this->cache = true; }
Eclaireur::~Eclaireur() {}
void Eclaireur::setCache() {}

// Géologue
Geologue::Geologue() : Player(3, "#886644") {}
Geologue::~Geologue() {}

// Ingénieur
Ingenieur::Ingenieur() : Player(4, "#0000FF") {}
Ingenieur::~Ingenieur() {}

// Grimpeur
Grimpeur::Grimpeur() : Player(5, "#551166") {}
Grimpeur::~Grimpeur() {}

// Médecin
Medecin::Medecin() : Player(6, "#FFFFFF") {}
Medecin::~Medecin() {}

// Garde du corps
GardeDuCorps::GardeDuCorps() : Player(7, "#FF0000") { this->pv = 5; }
GardeDuCorps::~GardeDuCorps() {}

// Chef
Chef::Chef() : Player(8, "#002200") {}
Chef::~Chef() {}