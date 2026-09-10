#ifndef TABLERO_H
#define TABLERO_H

unsigned short bytesNecesarios(unsigned short filas, unsigned short columnas);
unsigned char* crearTablero(unsigned short filas, unsigned short columnas);
void eliminarTablero(unsigned char* tablero);

// getters - setters
unsigned char leerFicha(unsigned char* tablero, unsigned short fila, unsigned short columna, unsigned short columnas);
void escribirFicha(unsigned char* tablero, unsigned short fila, unsigned short columna, unsigned short columnas, unsigned char valor);

#endif // TABLERO_H