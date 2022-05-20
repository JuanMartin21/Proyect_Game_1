#ifndef fecha_H
#define fecha_H

#include "boolean.h"

//Crear tipo estructurado para Fecha
typedef struct
{
    int dia;
    int mes;
    int anio;
} Fecha;

//cabezales sintacticos de subprogramas
void cargarFecha(Fecha &f);
void mostrarFecha(Fecha f);
boolean validarFecha(Fecha f);
boolean fechasIguales(Fecha f1, Fecha f2);
boolean primerFechaMayor(Fecha f1, Fecha f2);

//cabezales de funciones selectoras
int darDia(Fecha f);
int darMes(Fecha f);
int darAnio(Fecha f);

#endif
