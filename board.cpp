#include <iostream>

#include "board.h"
#include "memory.h"

using namespace std;

uint8_t** createBoard(int width, int height){

    int bytesPerRow = width / 8;

    uint8_t** board = reserveRows(height);

    for(int i=0; i<height; i++){
        board[i] = reserveRow(bytesPerRow);
    }

    return board;
};

void clearBoard(uint8_t** board, int height){
    for(int i=0; i<height; i++){
        deleteRow(board[i]); // Eliminar filas
    };
    deleteRows(board); // Eliminar tablero (memoria de Rows liberadas, pero el board apunta a direcciones invalidas)
};

void setBit(uint8_t** board, int row, int col){
    int byteIdx = col / 8;
    int bitPos = 7 - (col % 8);

    board[row][byteIdx] |= static_cast<uint8_t>(1 << bitPos);
};

void clearBit(uint8_t** board, int row, int col){
    int byteIdx = col / 8;
    int bitPos = 7 - (col % 8);

    board[row][byteIdx] &= static_cast<uint8_t>(~(1 << bitPos));
};

bool getBit(uint8_t** board, int row, int col){
    int byteIdx = col / 8;
    int bitPos = 7 - (col % 8);

    bool bit = (board[row][byteIdx] >> bitPos) & 1;

    return bit;
};

// Necesarias?
uint8_t getRowByte(uint8_t** board, int row, int byteIdx) {
    return board[row][byteIdx];
};

void orRowByte(uint8_t** board, int row, int byteIdx, uint8_t mask) {
    board[row][byteIdx] |= mask;
};

// Logica Rows
bool fullRow(uint8_t** board, int row, int bytesPerRow){
    for(int i=0; i<bytesPerRow; i++){
        if(board[row][i] != 0xFF){
            return false;
        };
    };
    return true;
};

void clearRow(uint8_t** board, int row, int bytesPerRow){
    for(int i=0; i<bytesPerRow; i++){
        board[row][i] = 0x00;
    };
};

void downRow(uint8_t** board, int rowToDelete, int bytesPerRow){
    uint8_t* deleteRow = board[rowToDelete];

    for(int i=rowToDelete; i>0; i--){
        board[i] = board[i-1];
    };

    board[0] = deleteRow;
    clearRow(board, 0, bytesPerRow);
};

// Imprimir tablero
void printBoard(uint8_t** board, int width, int height){
    for(int i=0; i<height; i++){
        cout << "|";
        for(int j=0; j<width; j++){
            if(getBit(board, i, j)){
                cout << "#";
            }else{
                cout << ".";
            };
        };
        cout << "|" << endl;
    };

    cout << "+";
    for(int i=0; i<width; i++){
        cout << "-";
    };
    cout << "+" << endl;

};





