#ifndef FIELD_H
#define FIELD_H

#include "cube.h"
#include <array>

using namespace std;

class block {
    int row, col;
    cube** fieldElements;
    array<int, 2> emptyPosition;

    void shuffleFieldElements();
    bool isValidFishka(int fishkaNumber);
    const array<int, 2>& getPositionOnField(int fishkaNumber);

public:
    block(int row, int col);
    ~block();
    void fillAndShuffle();
    void display() ;
    void moveFishka(int fishkaNumber);
};

#endif // FIELD_H


