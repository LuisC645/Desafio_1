#include "juego.h"
#include "tablero.h"
#include <cstdlib>

void tableroAleatorio(unsigned char* tablero, unsigned short filas, unsigned short columnas){
    for (unsigned short f = 0; f < filas; f++) {
        for (unsigned short c = 0; c < columnas; c++) {
            unsigned char fichaRandom = (rand() % 6) + 1; // (0 a 5) + 1
            escribirFicha(tablero, f, c, columnas, fichaRandom);
        }
    }
}

void rellenarTablero(unsigned char* tablero, unsigned short filas, unsigned short columnas){

    for (unsigned short c = 0; c < columnas; c++) {
        for (unsigned short f = 0; f < filas; f++) {

            unsigned char ficha = leerFicha(tablero, f, c, columnas);
            if(ficha == 0){
                unsigned char nuevaFicha = (rand() % 6) + 1;
                escribirFicha(tablero, f, c, columnas, nuevaFicha);
            } else {
                break;
            }
        }
    }

}

void aplicarGravedad(unsigned char* tablero, unsigned short filas, unsigned short columnas){

    for (unsigned short c = 0; c < columnas; c++) {

        short vacio = filas - 1;

        for (short f = filas - 1; f >= 0; f--) {

            unsigned char ficha = leerFicha(tablero, f, c, columnas);

            if(ficha != 0){
                if(vacio != f){
                    escribirFicha(tablero, vacio, c, columnas, ficha);
                    escribirFicha(tablero, f, c, columnas, 0);
                }
                vacio--;
            }

        }
    }

}



