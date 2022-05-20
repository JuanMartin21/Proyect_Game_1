#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "string.h"
#include "arbolSociedad.h"

void agregarSocioArch(string nomArch, Socio s);
void agregarHabilidadArch(string nomArch, Habilidad h);
void desplegarSocioArch(string nomArch);
void desplegarHabilidadArch(string nomArch);
// Despliega por pantalla los enteros almacenados en el archivo. Precondición: El archivo existe

#endif
