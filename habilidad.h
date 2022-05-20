#ifndef HABILIDAD_H
#define HABILIDAD_H

#include "tipoHabilidad.h"
#include "string.h"
#include "fecha.h"
#include <stdio.h>

typedef struct
{
    string nombre_habilidad;
    long int ci_fantastica;
    Fecha f_Manifestacion;
    TipoHabilidad tipo_habilidad;
} Habilidad;

/// carga una habilidad
void cargarHabilidad(Habilidad &habil);

void mostrarHabilidad(Habilidad habil);

/// despliega una habilidad
void darHabilidad(Habilidad habil);

void darnombreHabil(Habilidad habil);

long int darCiFantastica(Habilidad habil); /// revisar comienzo funcion long int

Fecha darFechaManifestacion(Habilidad habil);

TipoHabilidad darTipoHabilidad(Habilidad habil);

void bajar_habilidad(Habilidad habil, FILE *f);

void levantarHabilidad(Habilidad &habil, FILE *f);

#endif // HABILIDAD_H_INCLUDED
