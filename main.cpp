#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tablero.h"
#include "visualizacion.h"
#include "juego.h"

using namespace std;

int main() {

    srand(time(0));

    unsigned short filas = 4;
    unsigned short columnas = 4;

    cout << "Creando tablero de " << filas << "x" << columnas << endl;
    unsigned char* tablero = crearTablero(filas, columnas);

    // Rellenar tablaro
    tableroAleatorio(tablero, filas, columnas);
    cout << "\n--- 1. TABLERO ALEATORIO ---\n";
    mostrarTableroSimbolos(tablero, filas, columnas);

    // Escribir 0 pa proba
    escribirFicha(tablero, 2, 1, columnas, 0); // Fila 2, Col 1 -> Vacio
    escribirFicha(tablero, 3, 1, columnas, 0); // Fila 3, Col 1 -> Vacio
    escribirFicha(tablero, 3, 2, columnas, 0); // Fila 3, Col 2 -> Vacio

    cout << "\n--- 2. TABLERO CON HUECOS ---\n";
    mostrarTableroSimbolos(tablero, filas, columnas);

    // la gravity
    aplicarGravedad(tablero, filas, columnas);
    cout << "\n--- 3. TRAS LA GRAVEDAD ---\n";
    mostrarTableroSimbolos(tablero, filas, columnas);

    // rellenar huecos
    rellenarTablero(tablero, filas, columnas);
    cout << "\n--- 4. TABLERO RELLENADO ---\n";
    mostrarTableroSimbolos(tablero, filas, columnas);

    eliminarTablero(tablero);

    return 0;
}