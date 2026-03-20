#include <iostream>
#include "memory.h"
#include "items.h"
#include "board.h"
#include "utils.h"

#include <ctime> // solo para aletoriedad

using namespace std;

// Aleatoriedad
static int nextType() {
    return rand() % TOTAL;
}

int main() {

    srand(static_cast<unsigned int>(time(nullptr)));

    cout << nextType() <<endl;

    cout << "falta testear todo" << endl;

    return 0;
}
