#include <iostream>
#include "items.h"

using namespace std;

int main() {

    for(int i=0; i<5; i++){
        for(int j=0; j<4; j++){

            cout << "Figura " << i << " - Rotacion " << j << endl;

            for (int row = 0; row < 4; ++row) {
                for (int col = 0; col < 4; ++col) {
                    if (getBitFigure(i, j, row, col)) {
                        cout << "#";
                    } else {
                        cout << ".";
                    }
                }
                cout << "\n";
            }

            cout << "Dimensiones: " << endl;
            cout << "Filas: " << getRowsFigure(i, j) << endl;
            cout << "Columnas: " << getColumnsFigure(i, j) << endl;

        }
    }

    return 0;
}
