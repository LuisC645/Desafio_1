#ifndef TABLERO_H
#define TABLERO_H

unsigned short bytesNecesarios(unsigned short filas, unsigned short columnas);
unsigned char* crearTablero(unsigned short filas, unsigned short columnas);
void eliminarTablero(unsigned char* tablero);

#endif // TABLERO_H