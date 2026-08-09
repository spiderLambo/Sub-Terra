#include "display/scenes/game.h"

Game::Game()
    : plateauData({nullptr}), plateau(&plateauData), coordonesPlateau(13, 13) {
  plateauData.placerTuile(EMANATION, {true, true, true, true}, 66, 66, 0);
  plateauData.placerTuile(EMANATION, {true, true, true, true}, 69, 66, 0);
  plateauData.placerTuile(EMANATION, {true, true, false, true}, 70, 66, 0);
  plateauData.placerTuile(EMANATION, {true, true, true, true}, 70, 70, 0);
  plateauData.placerTuile(EMANATION, {true, false, false, true}, 70, 74, 0);
  plateauData.placerTuile(EMANATION, {false, true, true, false}, 73, 74, 0);
  plateauData.placerTuile(EMANATION, {true, true, true, true}, 74, 74, 0);
}
Game::~Game() {}

void Game::VuePlateau() {
  view({0.7f * windowWidth, windowHeight - 50.0f}, {10.0f, 10.0f}, [this]() {
    plateau.Display(coordonesPlateau.first, coordonesPlateau.second);
  });
}

void Game::afficher() {
  VuePlateau();
  dessinerContours();
}
void Game::events() {
  Scene::events();
  if (event.type == sf::Event::KeyPressed) {
    if (event.key.code == sf::Keyboard::Left) coordonesPlateau.first -= 10;
    if (event.key.code == sf::Keyboard::Right) coordonesPlateau.first += 10;
    if (event.key.code == sf::Keyboard::Up) coordonesPlateau.second -= 10;
    if (event.key.code == sf::Keyboard::Down) coordonesPlateau.second += 10;
  }
}

void Game::dessinerContours() {
  float leftX = 0.3f * windowWidth - 50;
  float rightWidth = 0.7f * windowWidth + 35;
  float personHeight = 12 * (0.3f * windowWidth - 50) / 18.5f;
  float stackHeight = 0.9f * windowWidth / 6.5f;

  Rectangle ZonePlateau(sf::Vector2f(0.7f * windowWidth, windowHeight - 50),
                        sf::Vector2f(10.0f, 10.0f), sf::Color::Transparent,
                        sf::Color::White, 5.0f);
  ZonePlateau.Display();

  Rectangle ZonePerso(
      sf::Vector2f(leftX, 12 * (0.3f * windowWidth - 50) / 18.5f),
      sf::Vector2f(rightWidth, 10.0f), sf::Color::Blue, sf::Color::White, 5.0f);
  ZonePerso.Display();

  Rectangle StackEtDangers(sf::Vector2f(leftX, stackHeight),
                           sf::Vector2f(rightWidth, personHeight + 35),
                           sf::Color::Green, sf::Color::White, 5.0f);
  StackEtDangers.Display();

  Rectangle ZoneAutreJoueurs(
      sf::Vector2f(leftX,
                   windowHeight - 40 - (personHeight + 60 + stackHeight)),
      sf::Vector2f(rightWidth, personHeight + 60 + stackHeight), sf::Color::Red,
      sf::Color::White, 5.0f);
  ZoneAutreJoueurs.Display();
}
