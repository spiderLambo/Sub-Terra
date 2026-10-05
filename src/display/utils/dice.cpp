#include "display/utils/dice.h"

Dice::Dice (std::pair<int, int> coordones) : textures{
        Image("src/display/assets/dice/1.png", Size, {coordones.first - Size/2,coordones.second - Size/2}),
        Image("src/display/assets/dice/2.png", Size, {coordones.first - Size/2,coordones.second - Size/2}),
        Image("src/display/assets/dice/3.png", Size, {coordones.first - Size/2,coordones.second - Size/2}),
        Image("src/display/assets/dice/4.png", Size, {coordones.first - Size/2,coordones.second - Size/2}),
        Image("src/display/assets/dice/5.png", Size, {coordones.first - Size/2,coordones.second - Size/2}),
        Image("src/display/assets/dice/6.png", Size, {coordones.first - Size/2,coordones.second - Size/2})
      }, roll(false) {}
Dice::~Dice() {}

void Dice::DisplayRoll (unsigned int result) {
    if (std::chrono::steady_clock::now() < stoptime) {
        textures[RollDice()-1].Display();
    } else {
        textures[result-1].Display();
        if (std::chrono::steady_clock::now() > stoptime + std::chrono::seconds(1)) {
            roll = false;
        }
    }
}
bool Dice::isRolling () {return roll;}
void Dice::NowRoll () {
    roll = true;
    stoptime = std::chrono::steady_clock::now() + std::chrono::seconds(3);
}