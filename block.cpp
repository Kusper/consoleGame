#include "block.h"
#include <algorithm>
#include <ctime>
#include <iostream>

using namespace std;

block::block(int row, int col) : row(row), col(col) {
    fieldElements = new cube*[row];
    for (int i = 0; i < row; ++i) {
        fieldElements[i] = new cube[col];
    }
}

block::~block() {
    for (int i = 0; i < row; ++i) {
        delete[] fieldElements[i];
    }
    delete[] fieldElements;
    cout << "block Destructor" << endl;
}

void block::fillAndShuffle() {
    int value = row * col - 1;

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            fieldElements[i][j] = cube(value, i, j);
            --value;
        }
    }

    shuffleFieldElements();

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (fieldElements[i][j].getNumber() == 0) {
                emptyPosition = {i, j};
                return;
            }
        }
    }
}


void block::shuffleFieldElements() {
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            int random_row = rand() % row;
            int random_col = rand() % col;
            swap(fieldElements[i][j], fieldElements[random_row][random_col]);
        }
    }
}

void block::display() {
    cout << "========================" << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << fieldElements[i][j].getNumber() << "\t";
        }
        cout << endl;
    }
    cout << "========================" << endl;
}

bool block::isValidFishka(int fishkaNumber) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (fieldElements[i][j].getNumber() == fishkaNumber) {
                return true;
            }
        }
    }
    return false;
}

const array<int, 2>& block::getPositionOnField(int fishkaNumber) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (fieldElements[i][j].getNumber() == fishkaNumber) {
                array<int, 2>* position = new array<int, 2>{i, j};
                return *position;
            }
        }
    }
    throw out_of_range("Сube number not found");
}

void block::moveFishka(int fishkaNumber) {
    if (isValidFishka(fishkaNumber)) {
        std::array<int, 2> fishkaPosition = getPositionOnField(fishkaNumber);
        std::array<int, 2> zeroFishkaPosition = getPositionOnField(0);

        std::cout << "(" << fishkaNumber << ") " << fishkaPosition[0] << " " << fishkaPosition[1] << std::endl;
        std::cout << "(0) " << zeroFishkaPosition[0] << " " << zeroFishkaPosition[1] << std::endl;

        fieldElements[zeroFishkaPosition[0]][zeroFishkaPosition[1]].setNumber(fishkaNumber);
        fieldElements[fishkaPosition[0]][fishkaPosition[1]].setNumber(0);

    } else {
        cout << "Incorrect" << endl;
    }
}


