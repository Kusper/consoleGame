#include <iostream>
#include "block.h"

using namespace std;

int main() {
    block field(3, 3);
    field.fillAndShuffle();

    int number;
    do {
        field.display();
        cout << "Enter fishka number (enter -1 to exit): ";
        cin >> number;
        cout << "============================" << endl;

        if (number == -1) {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }

        field.moveFishka(number);
    } while (true);

    return 0;
}

