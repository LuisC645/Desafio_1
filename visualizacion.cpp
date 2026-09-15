#include <iostream>
#include "visualizacion.h"
#include "tablero.h"

using namespace std;

void mostrarTableroSimbolos(unsigned char* tablero, unsigned short filas, unsigned short columnas){

    const char simbolos[] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', '*'};

    cout << "\n---- Tablero Juego----\n" << "    ";

    for(unsigned short c = 0; c < columnas; ++c){
        cout << c << "   ";
    }

    cout << endl << "  ";

    for(unsigned short c = 0; c < columnas; ++c){
        cout << "----";
    }

    cout << endl;

    for (unsigned short f = 0; f < filas;++f) {

        cout << f << " | ";
        for(unsigned short c = 0; c < columnas; ++c){
            unsigned char valor = leerFicha(tablero, f, c, columnas);
            cout << simbolos[valor] << " | ";
        }

        cout << endl << "  ";

        for (unsigned int c = 0; c < columnas; ++c) {
            cout<< "----";
        }

        cout << endl;

    }

}

void mostrarTableroBinario(unsigned char* tablero, unsigned short filas, unsigned short columnas){

    cout << "\n---- Tablero Binario----\n" << "   ";

    for (unsigned short c = 0; c < columnas; c++) {
        cout << "  " << c << "   ";
    }

    cout << endl;

    for (unsigned short f = 0; f < filas; f++) {
        cout << f << "  ";

        for (unsigned short c = 0; c < columnas; c++) {
            unsigned char valor = leerFicha(tablero, f, c, columnas);
            cout << "[";

            for (short b = 2; b >= 0; b--) {
                cout << ((valor >> b) & 1); // bit 2 menos sig bit 0 mas
            }

            cout << "] ";
        }
        cout << "\n";

    }

}

void mostrarMemoriaFisica(unsigned char* tablero, unsigned short bytes){

    cout << "\n--- Memoria Binaria Fisica ---\n";

    for (unsigned short i = 0; i < bytes; i++) {
        cout << "Byte " << i << ": ";
        for (short b = 7; b >= 0; --b) {
            cout << ((tablero[i] >> b) & 1);// mas sig al menos sig
        }
        cout << endl;
    }
}