#ifndef JUEGO_H
#define JUEGO_H

void tableroAleatorio(unsigned char* tablero, unsigned short filas, unsigned short columnas);
void rellenarTablero(unsigned char* tablero, unsigned short filas, unsigned short columnas);
void aplicarGravedad(unsigned char* tablero, unsigned short filas, unsigned short columnas);

//Cascadas del niagara
unsigned short cascadas(unsigned char* tablero,
                        unsigned short filas,
                        unsigned short columnas,
                        unsigned short* combinacionesTotales,
                        unsigned int* fichasEliminadas,
                        unsigned int* puntuacion
                        );

bool eliminarFichaManual(unsigned char* tablero,
                         unsigned short filas,
                         unsigned short columnas,
                         unsigned short filaSel,
                         unsigned short colSel,
                         unsigned int* eliminacionesUsuario,
                         unsigned int* fichasEliminadas,
                         unsigned int* puntuacion
                         );


#endif // JUEGO_H