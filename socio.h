#ifndef SOCIO_H
#define SOCIO_H
#include "tipoMago.h"
#include "string.h"
#include "fecha.h"
#include <stdio.h>

typedef struct
{
    string nombre_socio;
    long int ci_fantastica;
    string dimension;
    Fecha f_nacimiento;
    TipoMago tipo_mago;
} Socio;

/// precondiciones
void cargarSocio(Socio &S);

void mostrarSocio(Socio s);

void darNombreSocio(Socio s, string &nom);

long int darCIFantasticaSocio(Socio s);

void darDimensionSocio(Socio s, string &dim);

Fecha darFnacimientoSocio(Socio s);

TipoMago darTipoMago(Socio s);

void copiarNombreSocio(Socio s1, string &nom);

void darListaHabilidades(Socio s);

void Bajar_Socio(Socio s, FILE *f);
// Escribe en el archivo los datos de la Socio P.
// Precondición: El archivo viene abierto para escritura.
void Levantar_Socio(Socio &s, FILE *f);
// Lee desde el archivo los datos de la Socio P.
// Precondición: El archivo viene abierto para lectura.

#endif
