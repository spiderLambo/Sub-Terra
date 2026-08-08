#include "display/scenes/game.h"

Game::Game() : plateauData({nullptr}), plateau(&plateauData) {
  plateauData.placerTuile(EMANATION, {true, true, true, true}, 66, 66, 0);
}
Game::~Game() {}

void Game::afficher() { plateau.Display(100, 100); }
void Game::events() { Scene::events(); }