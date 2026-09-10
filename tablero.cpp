#include "tablero.h"

// Bytes necesarios para generar tablero y demás xd
unsigned short bytesNecesarios(unsigned short filas, unsigned short columnas){
    unsigned short totalBits = filas * columnas * 3;
    return (totalBits + 7) / 8; // Redondear por encima
}

unsigned char* crearTablero(unsigned short filas, unsigned short columnas){
    unsigned short bytes = bytesNecesarios(filas, columnas);
    unsigned char* tablero = new unsigned char[bytes];

    for(unsigned short i = 0; i < bytes; i++){
        tablero[i] = 0;
    }

    return tablero;
}

void elimnarTablero(unsigned char* tablero){
    delete[] tablero;
}


unsigned char leerFicha(unsigned char* tablero, unsigned short fila, unsigned short columna, unsigned short columnas){
    unsigned short indice = (fila * columnas) + columna; // El paqt n del bit de interes
    unsigned short bitInicial = indice * 3; // El bit de interes (pos inicial)

    unsigned short byteIndice = bitInicial / 8; // Byte donde se encuentra la ficha
    unsigned short offset = bitInicial % 8; // Pos del bit en el byte de interes

    unsigned short ventana = tablero[byteIndice];

    if(offset > 5){
        ventana |= (tablero[byteIndice + 1] << 8);
    }

    return (ventana >> offset) & 0x07;
}

void escribirFicha(unsigned char* tablero, unsigned short fila, unsigned short columna, unsigned short columnas, unsigned char valor){
    unsigned short indice = (fila * columnas) + columna; // El paqt n del bit de interes
    unsigned short bitInicial = indice * 3; // El bit de interes (pos inicial)

    unsigned short byteIndice = bitInicial / 8; // Byte donde se encuentra la ficha
    unsigned short offset = bitInicial % 8; // Pos del bit en el byte de interes

    unsigned short ventana = tablero[byteIndice];

    if(offset > 5){
        ventana |= (tablero[byteIndice + 1] << 8);
    }

    // Poner 0 la ficha actual
    ventana &= ~(0x07 << offset);

    // Colocar el valor
    ventana |= ((valor & 0x07) << offset);

    // poner ventana en tablero
    tablero[byteIndice] = ventana & 0xFF;

    if(offset > 5){
        tablero[byteIndice + 1] = (ventana >> 8) & 0xFF;
    }
}

