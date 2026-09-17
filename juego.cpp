#include "juego.h"
#include "tablero.h"
#include "combinacion.h"
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

//Cascadas del niagara
unsigned short cascadas(unsigned char* tablero,
                        unsigned short filas,
                        unsigned short columnas,
                        unsigned short* combinacionesTotales,
                        unsigned int* fichasEliminadas,
                        unsigned int* puntuacion
                        ){

    unsigned short cascadasActuales = 0;
    unsigned short combosNuevos = 0;

    unsigned char* mascara = crearMascara(filas, columnas);

    while((combosNuevos = detectarCombinaciones(tablero,
                                                 mascara,
                                                 filas,
                                                 columnas,
                                                 puntuacion,
                                                 cascadasActuales + 1)) > 0){

        cascadasActuales++;
        *combinacionesTotales += combosNuevos;

        unsigned short destruidas = eliminarMarcados(tablero, mascara, filas, columnas);
        *fichasEliminadas += destruidas;

        aplicarGravedad(tablero, filas, columnas);
        rellenarTablero(tablero, filas, columnas);

        for(unsigned short i = 0; i < ((filas * columnas + 7) / 8); i++){
            mascara[i] = 0;
        }
    }

    destruirMascara(mascara);
    return cascadasActuales;

}

bool eliminarFichaManual(unsigned char* tablero,
                         unsigned short filas,
                         unsigned short columnas,
                         unsigned short filaSel,
                         unsigned short colSel,
                         unsigned int* eliminacionesUsuario,
                         unsigned int* fichasEliminadas,
                         unsigned int* puntuacion
                         ){

    if(filaSel >= filas || colSel >=  columnas){
        return false;
    }

    unsigned char ficha = leerFicha(tablero, filaSel, colSel, columnas);
    if (ficha == 0){
        return false;
    }

    escribirFicha(tablero, filaSel, colSel, columnas, 0);
    (*eliminacionesUsuario)++;
    (*fichasEliminadas)++;

    aplicarGravedad(tablero, filas, columnas);
    rellenarTablero(tablero, filas, columnas);

    return true;
}