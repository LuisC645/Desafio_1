#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tablero.h"
#include "visualizacion.h"
#include "juego.h"
#include "combinacion.h"
#include "redimensionar.h"
#include "utils.h"

using namespace std;

int main() {
    // Semilla aleatoria
    srand(time(0));

    unsigned short combinacionesTotales = 0;
    unsigned int fichasEliminadas = 0;
    unsigned int puntuacion = 0;
    unsigned int eliminacionesUsuario = 0;

    cout << "========================================\n";
    cout << "        BIENVENIDO A SWEET CRUSH        \n";
    cout << "========================================\n";

    unsigned short filas = validarEntrada("Ingrese el numero de filas (minimo 3): ", 0);
    unsigned short columnas = validarEntrada("Ingrese el numero de columnas (minimo 3): ", 0);

    unsigned short capacidadMem = bytesNecesarios(filas, columnas);
    unsigned char* tablero = crearTablero(filas, columnas);
    tableroAleatorio(tablero, filas, columnas);


    // Cascadas en tablero aleatorio
    cascadas(tablero, filas, columnas, &combinacionesTotales, &fichasEliminadas, &puntuacion);

    combinacionesTotales = 0;
    fichasEliminadas = 0;
    puntuacion = 0;
    eliminacionesUsuario = 0;

    bool jugando = true;

    while(jugando){

        cout << "\n========================================\n";
        cout << "               SWEET CRUSH              \n";
        cout << "========================================\n";

        // Stats
        cout << "Puntaje Actual : " << puntuacion << " puntos\n";
        cout << "Tablero        : " << filas << "x" << columnas << "\n";
        cout << "Eliminaciones  : Manuales (" << eliminacionesUsuario << ") | Totales (" << fichasEliminadas << ")\n";
        cout << "Combinaciones  : " << combinacionesTotales << "\n";
        cout << "----------------------------------------\n";

        mostrarTableroSimbolos(tablero, filas, columnas);

        cout << "\n[1] Eliminar ficha manual\n";
        cout << "[2] Agregar fila\n";
        cout << "[3] Eliminar fila\n";
        cout << "[4] Agregar columna\n";
        cout << "[5] Eliminar columna\n";
        cout << "[6] Mostrar tablero binario\n";
        cout << "[7] Mostrar memoria\n";
        cout << "[0] Salir\n";
        cout << "> Seleccione una accion: ";

        unsigned short op = validarEntrada("Ingrese opcion: ", 2);

        unsigned short f, c;
        unsigned int puntajeAnterior = puntuacion;

        switch(op) {

        case 1:

            f = validarEntrada("Fila: ", 1);
            c = validarEntrada("Columna: ", 1);

            if (eliminarFichaManual(tablero, filas, columnas, f, c, &eliminacionesUsuario, &fichasEliminadas, &puntuacion)) {
                unsigned int cascadasNum = cascadas(tablero, filas, columnas, &combinacionesTotales, &fichasEliminadas, &puntuacion);
                unsigned long puntosGanados = puntuacion - puntajeAnterior;
                cout << "\n[+] Movimiento exitoso! + " << puntosGanados << " puntos.";
                if (cascadasNum > 0) {
                    cout << " (Cascadas encadenadas: " << cascadasNum << ")";
                }
                cout << "\n";
            } else {
                cout << "\n[!] Posicion invalida o vacia.\n";
            }
            break;


        case 2:

            cout << "\nPosicion para nueva fila entre 0 y " << filas << endl;
            f =  validarEntrada("Ingrese posocion de la fila: ", 1);

            if (f <= filas) {
                tablero = agregarFila(tablero, &filas, columnas, f, &capacidadMem);
                cascadas(tablero, filas, columnas, &combinacionesTotales, &fichasEliminadas, &puntuacion);
                cout << "\n[+] Fila agregada correctamente.\n";
            } else {
                cout << "Error: valor invalido\n";
            }
            break;


        case 3:

            cout << "Fila a eliminar entre 0 y " << filas - 1 << endl;
            f = validarEntrada("Ingrese posicion de la fila: ", 1);

            if (f < filas && filas > 1) {
                tablero = eliminarFila(tablero, &filas, columnas, f, &capacidadMem);
                cascadas(tablero, filas, columnas, &combinacionesTotales, &fichasEliminadas, &puntuacion);
                cout << "\n[+] Fila eliminada correctamente.\n";
            } else {
                cout << "Error: valor invalido\n";
            }
            break;

        case 4:

            cout << "Posicion para nueva columna entre 0 y " << columnas << endl;
            c = validarEntrada("Ingrese columna: ", 1);
            if (c <= columnas) {
                tablero = agregarColumna(tablero, filas, &columnas, c, &capacidadMem);
                cascadas(tablero, filas, columnas, &combinacionesTotales, &fichasEliminadas, &puntuacion);
                cout << "\n[+] Columna agregada correctamente.\n";
            } else {
                cout << "Error: valor invalido\n";
            }
            break;

        case 5:

            cout << "Columna a eliminar entre 0 y " << columnas - 1 << endl;
            c = validarEntrada("Ingresa columna", 1);
            if (c < columnas && columnas > 1) {
                tablero = eliminarColumna(tablero, filas, &columnas, c, &capacidadMem);
                cascadas(tablero, filas, columnas, &combinacionesTotales, &fichasEliminadas, &puntuacion);
                cout << "\n[+] Columna eliminada correctamente.\n";
            } else {
                cout << "Error: Valor invalido\n";
            }
            break;

        case 6:

            mostrarTableroBinario(tablero, filas, columnas);
            break;

        case 7:

            mostrarMemoriaFisica(tablero, bytesNecesarios(filas, columnas));
            break;
        case 0:

            jugando = false;
            break;

        default:
            cout << "\n[!] Opcion no valida.\n";
        }
    }

    eliminarTablero(tablero);
    cout << "Juego terminado, memoria liberada";
    return 0;
}