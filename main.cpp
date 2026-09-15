#include <iostream>
#include "tablero.h"
#include "visualizacion.h"

using namespace std;

int main() {
    unsigned short filas = 3;
    unsigned short columnas = 3;
    unsigned short bytes = bytesNecesarios(filas, columnas);

    cout << "Tablero de " << filas << "x" << columnas << " (" << bytes << " bytes)" << endl;
    unsigned char* tablero = crearTablero(filas, columnas);

    escribirFicha(tablero, 0, 0, columnas, 1); // Ficha A (001)
    escribirFicha(tablero, 0, 1, columnas, 2); // Ficha B (010)
    escribirFicha(tablero, 0, 2, columnas, 3); // Ficha C (011)
    escribirFicha(tablero, 1, 0, columnas, 4); // Ficha D (100)
    escribirFicha(tablero, 1, 1, columnas, 5); // Ficha E (101)
    escribirFicha(tablero, 1, 2, columnas, 6); // Ficha F (110)
    escribirFicha(tablero, 2, 0, columnas, 0); // Ficha 0 (000)
    escribirFicha(tablero, 2, 1, columnas, 7); // Ficha * (111)
    escribirFicha(tablero, 2, 2, columnas, 2); // Ficha B (010)

    mostrarTableroSimbolos(tablero, filas, columnas);
    mostrarTableroBinario(tablero, filas, columnas);
    mostrarMemoriaFisica(tablero, bytes);

    eliminarTablero(tablero);

    return 0;
}