#ifndef ITEMS_H
#define ITEMS_H

#include <cstdint>

#define I 0
#define O 1
#define T 2
#define S 3
#define L 4
#define TOTAL 5

// Logica
uint8_t getRowFigure(int type, int rot, int row); // Obtener fila
bool getBitFigure(int type, int rot, int row, int column); // Verificar ocupación (bit)
int rotate(int rot); // Rotar figura
int getRowsFigure(int type, int rot); // Tamaño en filas
int getColumnsFigure(int type, int rot); // Tamaño en columnas

#endif // ITEMS_H
