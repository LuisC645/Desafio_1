#include <iostream>
#include "items.h"
#include "board.h"
#include "utils.h"

#include <ctime> // solo para aletoriedad

using namespace std;

// Aleatoriedad
static int nextType() {
    return rand() % TOTAL;
}

int main() {

    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "==========================================================\n";
    cout << "                    Desafio 1 - Info 2                    \n";
    cout << "             Marcos Castrillon - Luis Castillo             \n";
    cout << "==========================================================\n";

    char restart = 'p';

    while(restart == 'p' || restart == 'P'){

        int width = 0;
        int height = 0;

        // validaciones
        width = validateSize(0); // Ancho
        height = validateSize(1); // Alto

        int bytesPerRow = width / 8;
        uint8_t** board = createBoard(width, height);

        int figureType = nextType();
        int figureRotation = 0;
        int figurePosX = (width / 2) - (getColumnsFigure(figureType, 0) / 2); // Figure en centro de board
        int figurePosY = 0;
        int score = 0;
        bool gameOver = false;

        if(colision(board, width, height, bytesPerRow, figureType, figureRotation, figurePosX, figurePosY)){
            gameOver = true;
        }

        while(!gameOver){

            printBoardFigure(board, width, height, figureType, figureRotation, figurePosX, figurePosY, score);

            cout << "Accion (a=izq | d=der | s=bajar | r=rotar): ";
            char input = ' ';
            cin  >> input;

            inputKey(board, width, height, bytesPerRow, figureType, figureRotation, figurePosX, figurePosY, input);

            if(!colision(board, width, height, bytesPerRow, figureType, figureRotation, figurePosX, figurePosY + 1)){
                figurePosY++;
            } else {

                setFigure(board, bytesPerRow, figureType, figureRotation, figurePosX, figurePosY);

                int deleted = clearRows(board, height, bytesPerRow);
                score += deleted * 100;

                if(deleted > 0){
                    cout << "Fila(s) eliminadas: " << deleted << endl;
                }

                figureType = nextType();
                figureRotation = 0;
                figurePosX = (width / 2) - (getColumnsFigure(figureType, 0) / 2);
                figurePosY = 0;

                if(colision(board, width, height, bytesPerRow, figureType, figureRotation, figurePosX, figurePosY)){
                    gameOver = true;
                    printBoardFigure(board, width, height, figureType, figureRotation, figurePosX, figurePosY, score);
                    cout << "GAME OVER" << endl;
                    cout << "Puntaje: "<< score << endl;
                }
            }
        }

        clearBoard(board, height);
        cout << "\nPresiona 'p' para volver a jugar o cualquier otra tecla para salir: ";
        cin >> restart;
    }

    cout << "Juego finalzado";
    return 0;
}
