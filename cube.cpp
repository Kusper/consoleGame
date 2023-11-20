#include "cube.h"

cube::cube() : number(0), position{0, 0} {}

cube::cube(int number, int x, int y) : number(number) {
    position[0] = x;
    position[1] = y;
}

int cube::getNumber() { return number; }

const int* cube::getPosition() { return position; }

void cube::setNumber(int fishkaNumber) { number = fishkaNumber; }

void cube::setPosition(int posX, int posY) {
    position[0] = posX;
    position[1] = posY;
}

cube::~cube() {}