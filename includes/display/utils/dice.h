#pragma once
#include <array>
#include <chrono>

#include "utils/Dice.h"
#include "display/engine/texture.h"

class Dice {
    private:
        const int Size = 400;
        std::array <Image, 6> textures;
        bool roll;
        std::chrono::steady_clock::time_point stoptime;

    public:
        Dice(std::pair<int, int> coordones);
        ~Dice();
        void DisplayRoll(unsigned int result);
        bool isRolling ();
        void NowRoll ();
};