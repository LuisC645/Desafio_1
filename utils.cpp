#include "utils.h"
#include <iostream>
using namespace std;

// Tipo 0 = Ingresar filas, cols (no < 3)
// Tipo 1 = demas numeros
// Tipo 2 = Emtre 0 a 6 para menu

unsigned short validarEntrada(const char* texto, unsigned short tipo){

    char num[50];
    unsigned short valor = 0;
    bool entradaValida = false;

    while (!entradaValida) {
        cout << texto;
        cin >> num;

        bool soloDigitos = true;
        short temporal = 0;

        for (short i = 0; num[i] != '\0'; i++) {

            if (num[i] < 48 || num[i] > 57) {
                soloDigitos = false;
                break;
            }

            temporal = (temporal * 10) + (num[i] - 48);
        }

        // 0, 1, 2
        if (!soloDigitos || (tipo == 0 && temporal < 3) || (tipo == 2 && temporal > 6)) {
            cout << "Error: Entrada invalida" << endl;
        } else {
            valor = temporal;
            entradaValida = true;
        }
    }

    return valor;
}