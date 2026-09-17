#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tablero.h"
#include "visualizacion.h"
#include "juego.h"
#include "combinacion.h"

using namespace std;

int main() {
    // Semilla aleatoria
    srand(time(0));

    unsigned short filas = 6;
    unsigned short columnas = 6;

    // Variables de estado del juego pasadas por puntero
    unsigned short combinacionesTotales = 0;
    unsigned int fichasEliminadas = 0;
    unsigned int puntuacion = 0;

    cout << "Inicializando memoria del tablero...\n";
    unsigned char* tablero = crearTablero(filas, columnas);

    // Crear Tablero
    cout << "\n--- 1. TABLERO INICIAL ALEATORIO ---\n";
    tableroAleatorio(tablero, filas, columnas);
    mostrarTableroSimbolos(tablero, filas, columnas);
    mostrarTableroBinario(tablero, filas, columnas);


    cout << "\n--- 2. CASCADAS ALEATORIAS MAYBE ---\n";
    unsigned short cascadasIniciales = cascadas(tablero, filas, columnas, &combinacionesTotales, &fichasEliminadas, &puntuacion);
    mostrarTableroSimbolos(tablero, filas, columnas);
    cout << ">> Cascadas automaticas: " << cascadasIniciales << "\n";

    // Eliminar fichoza
    cout << "\n--- 3. Eliminar fixhoza ---\n";
    cout << "Tres fichas 'A' en la parte superior izquierda.\n";
    escribirFicha(tablero, 0, 0, columnas, 1);
    escribirFicha(tablero, 0, 1, columnas, 1);
    escribirFicha(tablero, 0, 2, columnas, 1);
    mostrarTableroSimbolos(tablero, filas, columnas);

    // funciono?
    cout << "\n--- Ojala funcione: ---\n";
    unsigned short cascadasJugada = cascadas(tablero, filas, columnas, &combinacionesTotales, &fichasEliminadas, &puntuacion);
    mostrarTableroSimbolos(tablero, filas, columnas);

    // stats pa
    cout << "\n--- stats pa ---\n";
    cout << "Puntuacion total: " << puntuacion << "\n";
    cout << "Fichas destruidas: " << fichasEliminadas << "\n";
    cout << "Combinaciones halladas: " << combinacionesTotales << "\n";
    cout << "Cascadas en el ultimo movimiento: " << cascadasJugada << "\n";

    eliminarTablero(tablero);

    return 0;
}