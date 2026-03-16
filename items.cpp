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
#include "items.h"

using namespace std;

// Crear piezas y guardarlas en flash (rom)
static const uint8_t figure[TOTAL][4][4] = {

// I
{
    { 0x80, 0x80, 0x80, 0x80 }, // rot 0
    { 0xF0, 0x00, 0x00, 0x00 }, // rot 1
    { 0x80, 0x80, 0x80, 0x80 }, // rot 3
    { 0xF0, 0x00, 0x00, 0x00 }  // rot 2
},

    // O
    {
        { 0xC0, 0xC0, 0x00, 0x00 }, // rot 0
        { 0xC0, 0xC0, 0x00, 0x00 }, // rot 1
        { 0xC0, 0xC0, 0x00, 0x00 }, // rot 2
        { 0xC0, 0xC0, 0x00, 0x00 }  // rot 3
    },

    // T
    {
        { 0xE0, 0x40, 0x00, 0x00 }, // rot 0
        { 0x40, 0xC0, 0x40, 0x00 }, // rot 1
        { 0x40, 0xE0, 0x00, 0x00 }, // rot 2
        { 0x80, 0xC0, 0x80, 0x00 }  // rot 3
    },

    // S
    {
        { 0x60, 0xC0, 0x00, 0x00 }, // rot 0
        { 0x80, 0xC0, 0x40, 0x00 }, // rot 1
        { 0x60, 0xC0, 0x00, 0x00 }, // rot 2
        { 0x80, 0xC0, 0x40, 0x00 }  // rot 3
    },

// L
{
    { 0x80, 0x80, 0xC0, 0x00 }, // rot 0
        { 0xE0, 0x80, 0x00, 0x00 }, // rot 1
        { 0xC0, 0x40, 0x40, 0x00 }, // rot 2
        { 0x20, 0xE0, 0x00, 0x00 }  // rot 3
}
};

// Ajustar shape a figures (Controlar bloques invisibles)
static const int rowsActive[TOTAL][4] = {
    { 4, 1, 4, 1 }, // I
    { 2, 2, 2, 2 }, // O
    { 2, 3, 2, 3 }, // T
    { 2, 3, 2, 3 }, // S
    { 3, 2, 3, 2 }  // L
};

static const int columnsActive[TOTAL][4] = {
    {1, 4, 1, 4}, // I
    {2, 2, 2, 2}, // O
    {3, 2, 3, 2}, // T
    {3, 2, 3, 2}, // S
    {2, 3, 2, 3}  // L
};

// Logica
uint8_t getRowFigure(int type, int rot, int row){
    return figure[type][rot][row];
};

bool getBitFigure(int type, int rot, int row, int column){
    return (figure[type][rot][row] >> (7 - column)) & 1;
};

int rotate(int rot){
    return (rot + 1) % 4; // 0, 1, 2, 3, 0
};

int getRowsFigure(int type, int rot){
    return rowsActive[type][rot];
};

int getColumnsFigure(int type, int rot){
    return columnsActive[type][rot];
};
