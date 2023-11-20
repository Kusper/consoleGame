#ifndef PROJECTS_FISHKA_H
#define PROJECTS_FISHKA_H

class cube {
private:
    int number;
    int position[2];

public:
    cube();
    cube(int number, int x, int y);
    int getNumber();
    const int* getPosition();
    void setNumber(int fishkaNumber);
    void setPosition(int posX, int posY);
    ~cube();
};

#endif //PROJECTS_FISHKA_H


