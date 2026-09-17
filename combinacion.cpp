#include "combinacion.h"
#include "tablero.h"

unsigned char* crearMascara(unsigned short filas, unsigned short columnas){

    unsigned short totalFichas = filas * columnas;
    unsigned short bytes = (totalFichas + 7) / 8;

    unsigned char* mascara = new unsigned char[bytes];

    for(unsigned short i = 0; i < bytes; i++){
        mascara[i] = 0;
    }

    return mascara;

}

void destruirMascara(unsigned char* mascara){
    delete[] mascara;
}

void marcarPosicion(unsigned char* mascara, unsigned short fila, unsigned short columna, unsigned short columnas){

    unsigned short indice = (fila * columnas) + columna;
    unsigned short byteIndice = indice / 8;
    unsigned short bitIndice = indice % 8;

    mascara[byteIndice] |= (1 << bitIndice);
}

bool estaMarcada(unsigned char* mascara, unsigned short fila, unsigned short columna, unsigned short columnas){

    unsigned int indice = (fila * columnas) + columna;
    unsigned int byteIndice = indice / 8;
    unsigned int bitIndice = indice % 8;
    return (mascara[byteIndice] >> bitIndice) & 1;

}

unsigned short detectarCombinaciones(unsigned char* tablero,
                                     unsigned char* mascara,
                                     unsigned short filas,
                                     unsigned short columnas,
                                     unsigned int* puntuacion,
                                     unsigned short nivelCascada
                                     ){

    unsigned short combinacionesEncontradas = 0;

    // Deteccion horizontal
    for(unsigned short f = 0; f < filas; f++){

        unsigned char actual = 0;
        unsigned short contador = 0;

        for(unsigned short c = 0; c < columnas; c++){

            unsigned char ficha = leerFicha(tablero, f, c, columnas);

            if(ficha != 0 && ficha != 7 && ficha == actual){
                contador++;
            } else {

                if(contador >= 3){

                    combinacionesEncontradas++;
                    unsigned int puntosBase = 0;

                    if(contador == 3){
                        puntosBase = 3 * 10;
                    } else {
                        puntosBase = contador * 20;
                    }

                    *puntuacion += (puntosBase * nivelCascada);

                    for(unsigned short i = 1; i <= contador; i++){
                        marcarPosicion(mascara, f, c - i, columnas);
                    }
                }

                actual = ficha;
                if(ficha != 0 && ficha != 7){
                    contador = 1;
                } else {
                    contador = 0;
                }
            }
        }
        if(contador >= 3){
            combinacionesEncontradas++;
            unsigned long puntosBase = (contador == 3) ? (3 * 10) : (contador * 20);
            *puntuacion += (puntosBase * nivelCascada);

            for (unsigned short i = 1; i <= contador; i++) {
                marcarPosicion(mascara, f, columnas - i, columnas);
            }
        }
    }


    // Deteccion vertical
    for(unsigned short c = 0; c < columnas; c++){

        unsigned char actual = 0;
        unsigned short contador = 0;

        for(unsigned short f = 0; f < filas; f++){

            unsigned char ficha = leerFicha(tablero, f, c, columnas);

            if(ficha != 0 && ficha != 7 && ficha == actual){
                contador++;
            } else {

                if(contador >= 3){

                    combinacionesEncontradas++;
                    unsigned int puntosBase = 0;

                    if(contador == 3){
                        puntosBase = 3 * 10;
                    } else {
                        puntosBase = contador * 20;
                    }

                    *puntuacion += (puntosBase * nivelCascada);

                    for(unsigned short i = 1; i <= contador; i++){
                        marcarPosicion(mascara, f - i, c, columnas);
                    }
                }

                actual = ficha;
                if(ficha != 0 && ficha != 7){
                    contador = 1;
                } else {
                    contador = 0;
                }
            }
        }
        if(contador >= 3){
            combinacionesEncontradas++;
            unsigned long puntosBase = (contador == 3) ? (3 * 10) : (contador * 20);
            *puntuacion += (puntosBase * nivelCascada);

            for (unsigned short i = 1; i <= contador; i++) {
                marcarPosicion(mascara, filas - i, c, columnas);
            }
        }
    }

    return combinacionesEncontradas;

}

unsigned short eliminarMarcados(unsigned char* tablero,
                                unsigned char* mascara,
                                unsigned short filas,
                                unsigned short columnas
                                ){

    unsigned short eliminadas = 0;

    for(unsigned short f = 0; f < filas; f++){
        for(unsigned short c = 0; c < columnas; c++){

            if(estaMarcada(mascara, f, c, columnas)){
                escribirFicha(tablero, f, c, columnas, 0);
                eliminadas++;
            }
        }
    }

    return eliminadas;

}