#include "chip8.h"

Chip8::Chip8() {}

Chip8::~Chip8() {}

void Chip8::setDrawFlag(bool value) {
    this->drawFlag = value;
}

bool Chip8::getDrawFlag() {
    return this->drawFlag;
}

void Chip8::init() {
    // Initialize registers and memory once
    this->drawFlag = true;
}

void Chip8::emulateCycle() {
    // Fetch Opcode
    // Decode Opcode
    // Execute Opcode
    // Update timers
}

void Chip8::loadGame(std::string gameName) {

}
