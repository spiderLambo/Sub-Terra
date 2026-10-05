#include "utils/Dice.h"

unsigned int RollDice () {
    static std::random_device seed;
    static std::mt19937 generator(seed());
    static std::uniform_int_distribution<unsigned int> distribution(1, 6);

    return distribution(generator);
}