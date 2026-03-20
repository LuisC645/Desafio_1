#ifndef UTILS_H
#define UTILS_H

#include <cstdint>

bool colision(uint8_t board, int width, int height, int bytesPerRow, int type, int rot, int posX, int posY);
void setFigure(uint8_t board, int bytesPerRow, int type, int rot, int posX, int posY);
int clearRows(uint8_t board, int height, int bytesPerRow);
void printBoardFigure(uint8_t board, int width, int height, int type, int rot, int posX, int posY, int score);
void inputKey(uint8_t** board, int width, int height, int bytesPerRow, int type, int& rot, int& posX, int& posY, char input);
long long validateNumbers(char input);

#endif // UTILS_H
