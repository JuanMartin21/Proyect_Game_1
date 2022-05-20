#ifndef TIPOHABILIDAD_H
#define TIPOHABILIDAD_H
#include <stdio.h>

typedef enum
{
    NATURAL,
    POCO_NATURAL,
    SOBRENATURAL
} TipoHabilidad;

void cargaTipoHabilidad(TipoHabilidad &TH);

void mostrarTipoHabilidad(TipoHabilidad TH);

#endif
