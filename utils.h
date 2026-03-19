#ifndef UTILS_H
#define UTILS_H

#include <cstdint>

// Definimos
// Aleatoriedad
// Colisiones
// Fijar figuras
// Limpiar filas llenas
// Imprimir estados
// Entrada teclado
// Datos válidos

// Aleatoriedad - NO IDEA - CAMBIAR

bool colision(uint8_t** board, int width, int height, int bytesPerRow, int type, int rot, int posX, int posY);
void setFigure(uint8_t** board, int width, int height, int bytesPerRow, int type, int rot, int posX, int posY);
int clearRows(uint8_t** board, int height, int bytesPerRow);




#endif // UTILS_H
