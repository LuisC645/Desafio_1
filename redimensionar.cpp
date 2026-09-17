#include "redimensionar.h"
#include "tablero.h"
#include <cstdlib>


unsigned char* agregarFila(unsigned char* tablero,
                           unsigned short* filas,
                           unsigned short columnas,
                           unsigned short posFila,
                           unsigned short* capacidadMem
                           ){

    unsigned short nuevasFilas = *filas + 1;
    unsigned short nuevosBytes = bytesNecesarios(nuevasFilas, columnas);

    unsigned char* nuevoTablero = new unsigned char[nuevosBytes];
    for (unsigned short i = 0; i < nuevosBytes; i++){
        nuevoTablero[i] = 0;
    }

    for(unsigned short f = 0; f < *filas; f++){

        unsigned short filaDestino = 0;

        if(f >= posFila){
            filaDestino = f + 1;
        } else {
            filaDestino = f;
        }

        for(unsigned short c = 0; c < columnas; c++){

            unsigned char ficha = leerFicha(tablero, f, c, columnas);
            escribirFicha(nuevoTablero, filaDestino, c, columnas, ficha);

        }
    }

    // Escribir en nueva filoski
    for (unsigned short c = 0; c < columnas; c++) {
        unsigned char nuevaFicha = (rand() % 6) + 1;
        escribirFicha(nuevoTablero, posFila, c, columnas, nuevaFicha);
    }

    delete[] tablero;
    *filas = nuevasFilas;
    *capacidadMem = nuevosBytes;

    return nuevoTablero;
}

unsigned char* eliminarFila(unsigned char* tablero,
                            unsigned short* filas,
                            unsigned short columnas,
                            unsigned short posFila,
                            unsigned short* capacidadMem
                            ){

    unsigned short nuevasFilas = *filas - 1;
    unsigned short nuevosBytes = bytesNecesarios(nuevasFilas, columnas);

    unsigned short umbral = (*capacidadMem * 65) / 100;
    bool reducirMemoria = (nuevosBytes < umbral);

    unsigned short bytesAsignar = 0;

    if(reducirMemoria){
        bytesAsignar = nuevosBytes;
    } else {
        bytesAsignar = *capacidadMem;
    }

    unsigned char* nuevoTablero = new unsigned char[bytesAsignar];
    for (unsigned int i = 0; i < bytesAsignar; i++){
        nuevoTablero[i] = 0;
    }

    for (unsigned short f = 0; f < *filas; f++) {

        if (f == posFila){
            continue; // Ignorar la fila que se esta eliminano
        }

        unsigned short filaDestino = 0;
        if(f > posFila){
            filaDestino = f - 1;
        } else {
            filaDestino = f;
        }

        for (unsigned short c = 0; c < columnas; c++) {
            unsigned char ficha = leerFicha(tablero, f, c, columnas);
            escribirFicha(nuevoTablero, filaDestino, c, columnas, ficha);
        }
    }

    delete[] tablero;
    *filas = nuevasFilas;

    if(reducirMemoria){
        *capacidadMem = nuevosBytes;
    }

    return nuevoTablero;
}

unsigned char* agregarColumna(unsigned char* tablero,
                              unsigned short filas,
                              unsigned short* columnas,
                              unsigned short posColumna,
                              unsigned short* capacidadMem
                              ){

    unsigned short nuevasColumnas = *columnas + 1;
    unsigned short nuevosBytes = bytesNecesarios(filas, nuevasColumnas);

    unsigned char* nuevoTablero = new unsigned char[nuevosBytes];
    for (unsigned short i = 0; i < nuevosBytes; i++){
        nuevoTablero[i] = 0;
    }

    for (unsigned short f = 0; f < filas; f++) {
        for (unsigned short c = 0; c < *columnas; c++) {

            unsigned short colDestino = 0;
            if(c >= posColumna){
                colDestino = c + 1;
            } else {
                colDestino = c;
            }

            unsigned char ficha = leerFicha(tablero, f, c, *columnas);
            escribirFicha(nuevoTablero, f, colDestino, nuevasColumnas, ficha);
        }
    }

    for (unsigned short f = 0; f < filas; f++) {
        unsigned char nuevaFicha = (rand() % 6) + 1;
        escribirFicha(nuevoTablero, f, posColumna, nuevasColumnas, nuevaFicha);
    }

    delete[] tablero;
    *columnas = nuevasColumnas;
    *capacidadMem = nuevosBytes;
    return nuevoTablero;

}

unsigned char* eliminarColumna(unsigned char* tablero,
                               unsigned short filas,
                               unsigned short* columnas,
                               unsigned short posColumna,
                               unsigned short* capacidadMem
                               ){

    unsigned short nuevasColumnas = *columnas - 1;
    unsigned short nuevosBytes = bytesNecesarios(filas, nuevasColumnas);

    unsigned short umbral = (*capacidadMem * 65) / 100;
    bool reducirMemoria = (nuevosBytes < umbral);

    unsigned short bytesAsignar = 0;
    if(reducirMemoria){
        bytesAsignar = nuevosBytes;
    } else {
        bytesAsignar = *capacidadMem;
    }

    unsigned char* nuevoTablero = new unsigned char[bytesAsignar];
    for (unsigned short i = 0; i < bytesAsignar; ++i){
        nuevoTablero[i] = 0;
    }

    for (unsigned short f = 0; f < filas; ++f) {
        for (unsigned short c = 0; c < *columnas; ++c) {

            if (c == posColumna){
                continue; // Ignorar la columna a eliminar
            }

            unsigned short colDestino = 0;
            if(c > posColumna){
                colDestino = c - 1;
            } else {
                colDestino = c;
            }

            unsigned char ficha = leerFicha(tablero, f, c, *columnas);
            escribirFicha(nuevoTablero, f, colDestino, nuevasColumnas, ficha);
        }
    }

    delete[] tablero;
    *columnas = nuevasColumnas;
    if (reducirMemoria) {
        *capacidadMem = nuevosBytes;
    }
    return nuevoTablero;

}