#include "memory.h"

//Reservar
uint8_t* reserveRow(int column){

    uint8_t* row = new uint8_t[column]; // Reservar N_column en memoria

    for(int i=0; i<column; i++){
        row[i] = 0x00; // Colocar en 0 elementos de fila
    };

    return row;
}

uint8_t** reserveRows(int height){
    uint8_t** rows = new uint8_t*[height]; // Guardar 1ra posicion de cada fila
    return rows;
}

// Eliminar
void deleteRow(uint8_t* reserveRow){
    delete[] reserveRow;
}

void deleteRows(uint8_t** reserveRows){
    delete[] reserveRows;
}
