#include <iostream>
#include "board.h"

using namespace std;

int main() {

    int width = 16;
    int height = 10;

    // Crear tablero
    uint8_t** board = createBoard(width, height);

    // Test bits
    setBit(board, 0, 0);
    setBit(board, 0, 1);
    setBit(board, 0, 2);

    setBit(board, 1, 5);
    setBit(board, 2, 10);
    setBit(board, 9, 15);

    printBoard(board, width, height);

    clearBoard(board, height);

    return 0;
}
