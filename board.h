#ifndef BOARD_H
#define BOARD_H

#include <cstdint>

uint8_t** createBoard(int width, int height);
void clearBoard(uint8_t** board, int height);

void setBit(uint8_t** board, int row, int col);
void clearBit(uint8_t** board, int row, int col);
bool getBit(uint8_t** board, int row, int col);

// Logica Rows
bool fullRow(uint8_t** board, int row, int bytesPerRow);
void clearRow(uint8_t** board, int row, int bytesPerRow);
void downRow(uint8_t** board, int rowToDelete, int bytesPerRow);

// Imprimir board
void printBoard(uint8_t** board, int width, int height);

#endif // BOARD_H
