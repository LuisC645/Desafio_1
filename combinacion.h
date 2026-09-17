#ifndef COMBINACION_H
#define COMBINACION_H

unsigned char* crearMascara(unsigned short filas, unsigned short columnas);
void destruirMascara(unsigned char* mascara);
void marcarPosicion(unsigned char* mascara, unsigned short filas, unsigned short columna, unsigned short columnas);
bool estaMarcada(unsigned char* mascara, unsigned short filas, unsigned short columna, unsigned short columnas);

unsigned short detectarCombinaciones(unsigned char* tablero,
                                     unsigned char* mascara,
                                     unsigned short filas,
                                     unsigned short columna,
                                     unsigned int* puntuación,
                                     unsigned short nivelCascada
                                     );

unsigned short eliminarMarcados(unsigned char* tablero,
                                unsigned char* mascara,
                                unsigned short filas,
                                unsigned short columna
                                );


#endif // COMBINACION_H