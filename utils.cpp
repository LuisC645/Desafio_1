#include <iostream>

#include "items.h"
#include "board.h"

using namespace std;

// Colisiones
bool colision(uint8_t** board, int width, int height, int bytesPerRow, int type, int rot, int posX, int posY){

    if(posX < 0){return true;}
    if(posX + getColumnsFigure(type, rot) > width){return true;}
    if(posY + getRowsFigure(type, rot) > height){return true;}

    int byteStart = posX / 8; // Columna
    int bitShift = posX % 8; // Posicion del bit dentro del byte

    for(int i=0; i<getRowsFigure(type, rot); i++){
        int boardRow = posY + i;
        if (boardRow < 0) continue;
        uint8_t bits = getRowFigure(type, rot, i);

        uint8_t memStart = bits >> bitShift; // byte inicio de figura

        if(board[boardRow][byteStart] & memStart){
            return true;
        }

        if(bitShift > 0 && (byteStart + 1) < bytesPerRow){
            uint8_t memEnd = bits << (8 - bitShift); // byte final de figura
            if(board[boardRow][byteStart+1] & memEnd){
                return true;
            }
        }
    }
    return false;
}

void setFigure(uint8_t** board, int bytesPerRow, int type, int rot, int posX, int posY){

    int byteStart = posX / 8; // Columna
    int bitShift = posX % 8; // Posicion del bit dentro del byte

    for(int i=0; i<getRowsFigure(type, rot); i++){

        int boardRow = posY + i;
        uint8_t bits = getRowFigure(type, rot, i);

        uint8_t memStart = bits >> bitShift;

        (board[boardRow][byteStart] |= memStart); // Pos bits memStart

        if(bitShift > 0 && (byteStart + 1) < bytesPerRow){
            uint8_t memEnd = bits << (8 - bitShift);
            board[boardRow][byteStart + 1] |= memEnd;
        }
    }
}

int clearRows(uint8_t** board, int height, int bytesPerRow){

    int deletes = 0;
    int temp = height - 1;

    while(temp >= 0){
        if(fullRow(board, temp, bytesPerRow)){
            downRow(board, temp, bytesPerRow);
            deletes++;
        } else{
            temp--;
        }
    }
    return deletes;
}


// Imprimir board + figure

void printBoardFigure(uint8_t** board, int width, int height, int type, int rot, int posX, int posY, int score){

    cout << endl << "Score: " << score << endl;

    for(int row=0; row < height; row++){
        cout << "|";

        for(int col=0; col < width; col++){

            bool taken = getBit(board, row, col);

            if(!taken){
                int figureRow = row - posY;
                int figureCol = col - posX;

                if(figureRow >= 0 && figureRow < getRowsFigure(type, rot) && figureCol >= 0 && getColumnsFigure(type, rot)){
                    taken = getBitFigure(type, rot, figureRow, figureCol);
                }
            }

            if(taken){
                cout << "#";
            }else{
                cout << ".";
            }
        }
        cout << "|" << endl;
    }
    cout << "+";
    for(int i=0; i<width; i++){
        cout << "-";
    }
    cout << "+" << endl;
}

// Entrada teclado

void inputKey(uint8_t** board, int width, int height, int bytesPerRow, int type, int& rot, int& posX, int& posY, char input){

    switch (input) {

    case 'a': case 'A':
        if (!colision(board, width, height, bytesPerRow, type, rot, posX - 1, posY)){
            posX--;
        } break;

    case 'd': case 'D':
        if (!colision(board, width, height, bytesPerRow, type, rot, posX + 1, posY)){
            posX++;
        } break;


    case 's': case 'S':
        if (!colision(board, width, height, bytesPerRow, type, rot, posX, posY + 1)){
            //posY++ Solución de error, doble salto
        } break;

    case 'r': case 'R': {
        int newRot = rotate(rot);
        if (!colision(board, width, height, bytesPerRow, type, newRot, posX, posY)){
            rot = newRot;
        } break;
    }

    default: break;
    }
}

// Validación entradas
int validateSize(int mode) {
    char num[20];
    int temp;

    while (true) {

        if(mode == 0){
            cout << "Ingrese el ancho del tablero (minimo 8, multiplo de 8): ";
        } else if(mode == 1){
            cout << "Ingrese el alto del tablero (minimo 8): ";
        }

        cin >> num;

        bool onlyNumbers = true;
        temp = 0;

        for (int i = 0; num[i] != '\0'; i++) {
            if (num[i] < 48 || num[i] > 57) {
                onlyNumbers = false;
                break;
            }
            temp = (temp * 10) + (num[i] - 48);
        }

        // Validar ancho
        if(mode == 0){
            // Validar multiplo
            if (!onlyNumbers || temp < 8 || temp % 8 != 0) {
                cout << "ERROR" << endl;
            } else {
                return temp;
            }
        }
        // Validar alto
        else if(mode == 1){
            // Validar minimo 8
            if (!onlyNumbers || temp < 8) {
                cout << "ERROR" << endl;
            } else {
                return temp;
            }
        }
    }
}
