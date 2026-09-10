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