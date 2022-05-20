#ifndef TIPOMAGO_H
#define TIPOMAGO_H
#include <stdio.h>

typedef enum
{
    BRUJO,
    HADA,
    HECHICERO
} TipoMago;

void cargarMago(TipoMago &Mago);

void mostrarMago(TipoMago Mago);

#endif
