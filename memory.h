#ifndef MEMORY_H
#define MEMORY_H

#include <cstdint>

uint8_t* reserveRow(int column); //Reserva de fila
void deleteRow(uint8_t* reserveRow); //Eliminar filas

uint8_t** reserveRows(int height); //Reserva de filas
void deleteRows(uint8_t** reserveRows); //Eliminar filas

#endif // MEMORY_H
