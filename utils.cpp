#include <iostream>

#include "memory.h"
#include "items.h"
#include "board.h"

using namespace std;

// Aleatoriedad - IDEA INVESTIGAR - CAMBIAR

static unsigned int semilla = 12345u;

static unsigned int siguienteAleatorio() {
    semilla = semilla * 1664525u + 1013904223u;
    return semilla;
}

static int siguienteTipo() {
    return static_cast<int>(siguienteAleatorio() % TOTAL);
}

// Colisiones

bool colision(uint8_t** board, int width, int height, int bytesPerRow, int type, int rot, int posX, int posY){

    if(posX < 0){return true;}
    if(posX + getColumnsFigure(type, rot) > width){return true;}
    if(posY + getRowsFigure(type, rot) > height){return true;}

    int byteStart = posX / 8; // Columna
    int bitShift = posX % 8; // Posicion del bit dentro del byte

    for(int i=0; i<getRowsFigure(type, rot); i++){
        int boardRow = posY + i;
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

void setFigure(uint8_t** board, int width, int height, int bytesPerRow, int type, int rot, int posX, int posY){

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






