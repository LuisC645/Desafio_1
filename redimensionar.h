#ifndef REDIMENSIONAR_H
#define REDIMENSIONAR_H

unsigned char* agregarFila(unsigned char* tablero,
                           unsigned short* filas,
                           unsigned short columnas,
                           unsigned short posFila,
                           unsigned short* capacidadMem
                           );

unsigned char* eliminarFila(unsigned char* tablero,
                            unsigned short* filas,
                            unsigned short columnas,
                            unsigned short posFila,
                            unsigned short* capacidadMem
                            );

unsigned char* agregarColumna(unsigned char* tablero,
                              unsigned short filas,
                              unsigned short* columnas,
                              unsigned short posFila,
                              unsigned short* capacidadMem
                              );

unsigned char* eliminarColumna(unsigned char* tablero,
                               unsigned short filas,
                               unsigned short* columnas,
                               unsigned short posFila,
                               unsigned short* capacidadMem
                               );

#endif // REDIMENSIONAR_H
