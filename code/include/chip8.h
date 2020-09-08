#pragma once

#include <string>
#include <iostream>

class Chip8 {
    private:
        bool drawFlag;

    public:
        Chip8();
        ~Chip8();
        void setDrawFlag(bool value);
        bool getDrawFlag();
        void init();
        void emulateCycle();
        void loadGame(std::string gameName);
};
